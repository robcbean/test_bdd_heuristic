require "#{File.dirname(__FILE__)}//utils.rb"
class FUNCTION
  def transformSplotClause(_feature_model, _clause)
    ret = _clause.clone()
    _feature_model.variables.sort { |x, y| -x.size <=> -y.size }.each do |variable|
      ret.gsub!(/#{variable.to_s}\b+/, variable_name(@var_list, _feature_model.variables.find_index(variable)))
    end
    ret.gsub!("not", "!")
    ret.gsub!("or", "|")
    ret.gsub!("and", "&")
    ret.gsub!(/\s+/, "")
    return ret
  end

  def addFeatureModelInputs(_feature_model)
    Range.new(0, _feature_model.variables.size-1).each do |variable|
      INPUT(variable)
    end
  end

  def getVariablesClause(_feature_model, _formula)
    ret = Array.new()

    variables = getVariablesFromCrossTree(_formula)
    variables.each do |variable|
      if _feature_model.variables.include?(variable.to_sym)
        ret << _feature_model.variables.find_index(variable.to_sym)
      end
    end
    ret = ret.uniq
    return ret
  end

  def processCrosstreeFromFeatureModel(_feature_model)

    cross_tree_clause = Clause.new(@id_genertor.next_id, "none", self)
    cross_tree_clause.name = "cross_tree"
    ids = Array.new()

    _feature_model.cross_tree.children.each do |feature|
      clause = Clause.new(@id_genertor.next_id, "none", self)
      clause.clause = self.transformSplotClause(_feature_model, feature.formula)
      clause.ex_clause = clause.clause.clone
      clause.orig_clause = feature.formula
      clause.name = feature.id
      self.add_variable(clause.id)
      clause.inputs = getVariablesClause(_feature_model, feature.formula)
      clause.orig_inputs = clause.inputs.clone
      cross_tree_clause.add_in_list(clause.id)
      #clause.add_in_list(clause.id)
      #self.INPUT(clause.id)
      ids << variable_name(@var_list, clause.id)

      #$stderr.print "cross_tree:#{clause.id} : #{clause.clause} #{clause.inputs}\n"
      self.clauses[clause.id] = clause

    end


    @clauses[cross_tree_clause.id] = cross_tree_clause
    cross_tree_clause.clause = ids.join("&")
    cross_tree_clause.ex_clause = cross_tree_clause.clause.clone
    cross_tree_clause.orig_inputs = cross_tree_clause.inputs.clone
    self.OUTPUT(cross_tree_clause.id)
    #print "cross_tree:#{cross_tree_clause.clause}\n"

    return cross_tree_clause.id


  end

  def processFeatureFromFeatureModel(_feature_model, _feature, _feature_to_clause = Hash.new())

    tree_clause = Clause.new(@id_genertor.next_id, "none", self)
    tree_clause.ex_clause = Array.new()
    tree_clause.name = _feature.id
    self.add_variable(tree_clause.id)

    if _feature.type == :root
      self.OUTPUT(tree_clause.id)
    end

    clause = Clause.new(@id_genertor.next_id, "none", self)
    clause.clause = self.transformSplotClause(_feature_model, _feature.formula)

    clause.orig_clause = _feature.formula
    if _feature.type != :root
      clause.clause = clause.clause.strip[1, clause.clause.size]
    end


    if not clause.clause.nil?
      clause.ex_clause = clause.clause.clone
    else
      clause.ex_clause = ""
    end
    clause.name = _feature.id
    clause.inputs = self.getVariablesClause(_feature_model, _feature.formula)
    clause.orig_inputs = clause.inputs.clone
    self.add_variable(clause.id)
    if not _feature_to_clause.keys.include?(_feature.id)
      _feature_to_clause[_feature.id] = tree_clause.id
    end

    @clauses[clause.id] = clause
    #print "feature:#{_feature.id}:#{_feature.type.to_s}\t#{_feature.formula}\t#{clause.clause}\t#{clause.inputs}\n"


    _feature.children.each do |feature|
      #if feature.children.size > 0
      # print "feature child (#{_feature.id}) #{feature.id}\n"
      self.processFeatureFromFeatureModel(_feature_model, feature, _feature_to_clause)
      #end
    end

    _feature.children.each do |feature|
      #print "feature child (#{_feature.type.to_s}) #{feature.id}\n"
      #if feature.children.size > 0
      tree_clause.inputs << _feature_to_clause[feature.id]
      tree_clause.ex_clause << variable_name(@var_list, _feature_to_clause[feature.id]) #"x[#{_feature_to_clause[feature.id]}]"
      #end
    end


    if tree_clause.inputs.size > 0
      tree_clause.ex_clause << variable_name(@var_list, clause.id)
      tree_clause.clause = tree_clause.ex_clause.join("&")
      tree_clause.ex_clause = tree_clause.clause.clone
      tree_clause.inputs << clause.id
      #print "tree feature (#{_feature.id}):#{tree_clause.id}:\t#{tree_clause.clause}\t#{tree_clause.inputs}\n"
      self.add_variable(clause.id)
    else
      tree_clause.clause = clause.clause
      if not tree_clause.clause.nil?
        tree_clause.ex_clause = tree_clause.clause.clone
      else
        tree_clause.ex_clause = ""
      end
      tree_clause.inputs = clause.inputs
      tree_clause.orig_clause = clause.orig_clause
      @clauses.delete(clause.id)
    end
    tree_clause.orig_inputs = tree_clause.inputs.clone
    @clauses[tree_clause.id] = tree_clause
    self.add_variable(tree_clause.id)

    return tree_clause.id

  end




  #ROB 01/11/2016 Get only symmetric groups
  def get_optimal_groups!(_variables,symmetric_groups)
    groups_to_be_removed = Array.new()

    $stderr.print("Finding optimal groups before #{symmetric_groups.length}\n")
    i = 0
    symmetric_groups.each do |group|
      $stderr.print("Group#{i} #{group.variables.to_s}\n")
      i = i + 1
    end

    objective_function = 'min: '
    constraints = ''
    verbose_constraints = ''
    verbose_objective_function ='min: '
    group_list = ''
    n_constraints = 0
    i = 0
    while i<symmetric_groups.length
      j = i+1
      while j<symmetric_groups.length
        if !(symmetric_groups[i].variables & symmetric_groups[j].variables).empty?
          #constraints << "-1 x#{i+1} -1 x#{j+1} >= -1;\n"
          constraints << "-1*g#{i} -1*g#{j} >= -1;\n"
          n_constraints = n_constraints + 1
        end
        j += 1
      end
      #objective_function << "-#{symmetric_groups[i].variables.length} x#{i+1} "
      objective_function << "-#{symmetric_groups[i].variables.length}*g#{i} "
      i += 1
    end
    #header = "* #variable= #{symmetric_groups.length} #constraint= #{n_constraints}\n*\n*\n"
    header = ""
    objective_function << ";\n"
    minisat_code = header+ group_list + objective_function + constraints
    File.open("minisat.opb", 'w+') do |file|
      file.write(minisat_code)
    end

    if !self.name.match("Dell").nil?
      opts = "-goal=-350 -1"
    else
      opts = ""
    end

    #sat4jpb_output = `java -jar sat4j-pb/sat4j-pb.jar sat4jpb.opb`
    if OS.linux?
        cmd = "minisat+/minisat+_script #{opts} ./minisat.opb"
    else
      if OS.mac?
        cmd = "minisat+/minisat_mac #{opts} ./minisat.opb"
      else
        cmd = "#{srcPathDOS}\\\\minisat+\\\\minisat+.exe #{opts} #{srcPathDOS}\\\\minisat.opb"
        print "cmd:#{cmd}\n"
      end
    end

    minisat_output = `#{cmd}`
    minisat_output =~ /s OPTIMUM FOUND\s+v\s+(.+?)\s+c _______________________________________________________________________________/m
    optimum = $1.split
    groups_to_be_removed = []

    optimum.each do |group|
      if group =~ /-/
        group =~ /g([0-9]+)/
        groups_to_be_removed << symmetric_groups[$1.to_i]
      end
    end

=begin
    solution_found = false
    minisat_output.each_line do |line|
      if line =~ /Found\s+\d+\s+solution\(s\)/
        solution_found = true
      elsif solution_found and line =~/v\s+/
        line.scan(/-x\d+/).each do |variable|
          group = variable.gsub("-x","")
          group = group.to_i - 1
          groups_to_be_removed << symmetric_groups[group]
        end
      end
    end

=end


    groups_to_be_removed.each do |group|
      symmetric_groups.delete(group)
    end

    $stderr.print("Finding optimal groups after #{symmetric_groups.length}\n")

    # #ROB 03/11/16 Change variable id for each value
     symmetric_groups.each do |group|
       new_variables = Array.new()
       group.variables.each do |variable|
         new_variables << variable_index(_variables,variable)
       end
       group.variables = new_variables
    end

  end





  # ROB 02/04/16 Process feature model splot file
  def loadFromSPLOTFile(_input_file)
    ret = nil
    if File.exist?(_input_file)
      ret = parse_splot(_input_file, false, true)
      @id_genertor.current = ret.variables.size
      self.addFeatureModelInputs(ret)
      fm_id = self.processFeatureFromFeatureModel(ret, ret.feature_model)

      clause = Clause.new(@id_genertor.next_id, "none", self)
      clause.null_function = true
      self.add_variable(clause.id)
      self.add_variable(fm_id)
      clause.add_in_list(fm_id)

      if ret.cross_tree.children.size > 0

        ct_id = self.processCrosstreeFromFeatureModel(ret)
        self.add_variable(ct_id)
        clause.add_in_list(ct_id)
        clause.orig_inputs = clause.inputs.clone
        clause.clause = variable_name(@var_list, ct_id) + "&" + variable_name(@var_list, fm_id)
        @clauses[clause.id] = clause
        self.add_variable(ct_id)
        self.add_output(clause.id)
      else
        clause.orig_inputs = clause.inputs.clone
        clause.clause = variable_name(@var_list, fm_id) + "&" + variable_name(@var_list, fm_id)
        @clauses[clause.id] = clause
        self.add_output(clause.id)

      end

      self.name = _input_file
      #ROB : 01/11/2016 Get optimals groups
      if @minisat
        get_optimal_groups!(ret.variables,ret.symmetric_groups)
      end
      #ROB : 01/11/2016 Get optimals groups

      self.extra_info = ret


    end
    return ret
  end
end