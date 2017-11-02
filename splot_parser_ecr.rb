require "#{File.dirname(__FILE__)}//bdd.rb"
require "#{File.dirname(__FILE__)}//remove_mandatory_features.rb"
require "#{File.dirname(__FILE__)}//corr_analysis_for_symmetry.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"

if  useNokogiri?
  require 'nokogiri'
end


class StatClauses
  attr_accessor :nclauses, :nsymmetric
end


class ComputedFormulaForSymmetricAnalysis
  attr_accessor :formula, :variables, :symmetric_groups, :ecr, :nclauses, :nsymmetric, :zformula, :feature_model, :cross_tree

  def initialize(_formula, _variables, _symmetric_groups, _ecr, _clauses, _nsymmetric, _zformula, _computed_tree, _cross_tree)
    @formula =_formula
    @variables = _variables
    @symmetric_groups = _symmetric_groups
    @ecr = _ecr
    @nclauses = _clauses
    @nsymmetric = _nsymmetric
    @zformula = _zformula
    @feature_model = _computed_tree
    @cross_tree = _cross_tree
  end
end


def getVariablesFromCrossTree(_clause)

  ret = Array.new()
  clean_clause = String.new(_clause)

  clean_clause.gsub!("(", ' ')
  clean_clause.gsub!(")", ' ')
  clean_clause.gsub!("~", ' ')
  #clean_clause.gsub!(" and ", ' ')
  #clean_clause.gsub!(" or ", ' ')

  clean_clause.split(/\s+/).each do |variable|
    if variable =~ /(_|[[:alnum:]])+/ and variable != "and" and variable !="or" and variable != "not"
      ret << variable.gsub(/\s/, '')
    end
  end
  return ret.uniq
end


class Feature
  attr_accessor :id, :type, :children, :parent, :formula

  def initialize(id, type, children, _formula="")
    @id = id
    @type = type
    @children = children
    @formula = _formula
  end
end

def feature(type, id, *children)
  ret = Feature.new(id, type, children)
  if ret.children
    ret.children.each do |child|
      child.parent = ret
    end
  end
  return ret
end

def isORandUniqueChild?(_feature)
  ret = (_feature.children.length == 1) and ((_feature.children[0].type == :or) or (_feature.children[0].type == :xor))
  return ret
end


def get_formula_from_tree(feature, formula, zformula, variables, symmetric_groups, _change_ids=true, _change_clause=false)

  ret = StatClauses.new()
  ret.nclauses = 0.0
  ret.nsymmetric = 0.0

  variables << feature.id

  if feature.type == :root
    feature.formula = "(#{feature.id})\n"
    formula << feature.formula
    # ROB : 19/05/15 add zformula
    zformula << "(#{feature.id})\n"
  end
  if not feature.parent.nil?
    if feature.parent.type == :xor or feature.parent.type == :or
      if _change_ids
        feature.id = feature.parent.id
      end
    end
  end

  if (feature.type == :or) or (feature.type == :xor)
    children_names = []
    feature.children.each do |child|
      children_names << child.id
    end
    symmetric_groups << SymmetricGroup.new(children_names, feature.type)
    if feature.parent.nil?
      feature_id = feature.id
    else
      feature_id = feature.parent.id
    end
    feature.formula = "\tand (not #{feature_id} or (#{children_names.join(' or ')}))\n"
    ret.nclauses = ret.nclauses+1
    ret.nsymmetric = ret.nsymmetric+1
    if (feature.type == :xor)
      children_combinatons = children_names.combination(2).to_a
      children_combinatons.each do |combination|
        feature.formula << "\tand (not #{combination[0]} or not #{combination[1]})\n"
        ##zformula << "\t "
        ret.nclauses = ret.nclauses+1
      end
    end
    formula << feature.formula
  end

  if !feature.children.empty?
    feature.children.each do |child|
      child.formula = ""

      feature_id = feature.id
      if feature.type == :xor or feature.type == :or
        if not feature.parent.nil?
          feature_id = feature.parent.id
        end
      end

      child_id = child.id
      if child.type == :xor or child.type == :or
        if not child.parent.nil?
          child_id = child.parent.id
        end
      end


      if child_id != feature_id
        child.formula << "\tand (not #{child_id} or #{feature_id})\n"
        ret.nclauses = ret.nclauses+1
        if (child.type == :mandatory) or (child.type == :or) or (child.type == :xor)
          child.formula << "\tand (not #{feature_id} or #{child_id})\n"
          ret.nclauses = ret.nclauses+1
        end
        if (child.type == :mandatory)
          symmetric_groups << SymmetricGroup.new([feature_id, child_id], child.type)
          ret.nsymmetric = ret.nsymmetric+2
        end
      else
        child.formula << "\t and (not #{feature_id} or #{feature_id})\n"
      end
      formula << child.formula
      tmp = get_formula_from_tree(child, formula, zformula, variables, symmetric_groups, _change_ids, _change_clause)
      ret.nclauses = ret.nclauses + tmp.nclauses
      ret.nsymmetric = ret.nsymmetric + tmp.nsymmetric
    end

  end

  return ret


end


def create_computed_tree(code)
  code =~ /<feature_tree>(.+)<\/feature_tree>/m
  # <process tree>
  tree = $1.strip
  processed_tree = ''
  previous_tabs = -1
  current_tabs = 0
  global_type = nil
  #ROB 10/05/15 If id is blank generate id Betty
  ngid = 0
  #ROB 10/05/15 If id is blank generate id Betty
  tree.each_line do |line|
    current_tabs = line.scan(/\t/).length
    if current_tabs == previous_tabs
      processed_tree += '),'
    elsif current_tabs < previous_tabs
      processed_tree += ([')']*(previous_tabs-current_tabs+1)).join('')
      processed_tree += ','
    end
    processed_tree += "\n"
    processed_tree += (["\t"]*current_tabs).join('')
    line =~ /\((.+)\)/
    id = $1
    #ROB : 22/06/2017 Name Id
    if id.nil?
      if not line =~ /:g/
        del_line = line.gsub(":r","")
        del_line = del_line.gsub(":m","")
        del_line = del_line.gsub(":o","")
        del_line = del_line.gsub(/\s/,"")
        id = del_line
      else
        ngid = ngid + 1
        id = "g#{ngid}"
      end
    end
    #ROB : 22/06/2017 Name Id

    id = id.gsub(":","")
    id = id.gsub(/\s/,"")
    id = id.gsub(/\W/,"")

    #ROB : 22/06/2017 Name Id
    if line =~ /:r/ or line =~ /r:/ # ROB : 10/05/15 Add also r: for Betty
      processed_tree += "feature(:root, :#{id},"
    elsif line =~ /:m/
      processed_tree += "feature(:mandatory, :#{id},"
    elsif line =~ /:o/
      processed_tree += "feature(:optional, :#{id},"
    elsif line =~ /:g/
      if line =~ /\[1,1\]/ #xor
        processed_tree += "feature(:xor, :#{id},"
      else #or
        processed_tree += "feature(:or, :#{id},"

      end
    elsif line =~ /:\s+/
      processed_tree += "feature(:global_child, :#{id},"
    end
    previous_tabs = current_tabs
  end

  processed_tree += ([')']*(previous_tabs+1)).join('')
  processed_tree.gsub!(/,[)]/, ')')

  ret = eval(processed_tree)

  return ret

end

def parse_splot(input_filename, _change_ids=true, _change_clause=false)

  file = File.open(input_filename)
  code = file.read
  file.close()
  changed = Hash.new()
  feature_model = create_computed_tree(code)
  #remove_mandatory_feature(computed_tree,changed)

  formula = []
  zformula = []
  variables = []
  symmetric_groups = []
  stats = get_formula_from_tree(feature_model, formula, zformula, variables, symmetric_groups, _change_ids, _change_clause)
  formula.uniq!
  zformula.uniq!
  formula = formula.join('')
  zformula = zformula.join('')
  variables.uniq!
  # <\process tree>

  # <crosstree constraints>
  clauses = Array.new()
  cross_tree_feature = Feature.new("CT0".to_sym, :crosstree, clauses)
  cross_tree_variables = Array.new()
  code =~ /<constraints>(.+)<\/constraints>/m
  crosstree = $1.strip
  crosstree.gsub!(/\sOR\s/, ' or ')
  crosstree.each_line do |line|

    # ROB : 07/02/15 Replace values in crosstree
    line =~ /:(.+)$/
    tmpclause = $1
    clause = ''
    features = Array.new()
    tmpclause.lines(' ').each do |word|
      findword = word.sub('~', '')
      if changed.has_key?(findword.to_sym)
        word.gsub!(Regexp.new(findword), changed[findword.to_sym].to_s)
      end
      features<<word
    end
    clause = features.join(' ')

    formula_variables = getVariablesFromCrossTree(clause)
    formula_variables.each do |variable|
      cross_tree_variables << variable
    end

    constraint = clause.gsub(/~/, 'not ')

    #ROB 01/04/16 Add formula
    contrait_feature = Feature.new("CT#{(cross_tree_feature.children.size+1).to_s}".to_sym, :crosstree, nil)
    contrait_feature.formula = constraint
    cross_tree_feature.children << contrait_feature
    formula += "\tand (#{constraint})\n"
    if constraint.=~ /not\s+\b(.+?)\b\s+or\s+not\s+\b(.+?)\b/
      symmetric_groups << SymmetricGroup.new([$1.to_sym, $2.to_sym], :excludes)
    end
  end

  # <\crosstree constraints>
  cross_tree_variables.uniq!
  ecr = cross_tree_variables.length.to_f / variables.length.to_f * 100.0
  return ComputedFormulaForSymmetricAnalysis.new(formula, variables, symmetric_groups, ecr, stats.nclauses, stats.nsymmetric, zformula, feature_model, cross_tree_feature)

end

def get_feature_model_name(_input_filename)
   doc = Nokogiri::XML(File.open(_input_filename))
   ret = doc.xpath('//feature_model').attribute("name").to_s
   return ret
end

def calc_symmetric_variables(_symmetric_groups)
  ret = 0.0
  tmp_variables = Array.new()
  _symmetric_groups.groups.each do |group|
    group.variables.each do |var|
      tmp_variables << var
    end
  end
  tmp_variables.uniq!
  ret = ret + tmp_variables.length
  return ret
end




