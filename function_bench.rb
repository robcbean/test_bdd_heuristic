class FUNCTION

  attr_accessor :transformations

  def benchKeywords()
    ret = ["INPUT\\(", "OUTPUT\\(", "NAND\\(", "AND\\(", "XOR\\(", "NOT\\(", "DFF\\(", "NOR\\(", "BUFF\\(", "OR\\("]
    return ret
  end

  def transformLine(_input)
    ret = _input.clone.gsub(/\s+/, "")
    ret.gsub!(".","_")
    if self.transformations.nil?
      self.transformations = Array.new()
    end

    tmp = ret.clone()

    self.benchKeywords().each do |word|
      tmp.gsub!(/#{word}/, "")
    end

    words = tmp.scan(/[[:word:]]+/).to_a
    words.sort_by!{ |x| -x.length }
    words.each do |word|
      if not self.benchKeywords.include?(word)
        if not self.transformations.include?(word)
          self.transformations << word
        end
        variable = self.transformations.find_index(word).to_s
        if ret =~ /\(\s*#{word}\s*\)/
          ret.gsub!(/\(\s*#{word}\s*\)/,"(#{variable})")
        elsif ret =~/\s*,#{word},\s*/
          ret.gsub!(/\s*,#{word},\s*/,",#{variable},")
        elsif ret =~ /\s*,#{word}\)\s*/
          ret.gsub!(/\s*,#{word}\)\s*/,",#{variable})")
        elsif ret =~ /\s*\(#{word}\s*,/
          ret.gsub!( /\s*\(#{word}\s*,/,"(#{variable},")
        elsif ret =~ /\s*#{word}\s*/
          ret.gsub!(/\s*#{word}\s*/,"#{variable}")
        end
      end
    end
    return ret
  end

  def addClauseToOrpanOutput()
    self.outputs.select { |output| not self.clauses.keys.include?(output) }.each do |output_id|
      clause = Clause.new(output_id,"DFF(#{output_id})",self)
      clause.orig_inputs = clause.inputs.clone
      self.clauses[clause.id] = clause
      if self.inputs.include?(output_id)
        self.inputs.delete(output_id)
      end
    end
  end

  def removeInputsNotIncludedInClauses()
    self.inputs.each do |input|
      tmp_out = self.clauses.values.select { |clause| clause.inputs.include?(input)}
      if tmp_out.size == 0
        self.inputs.delete(input)
      end
    end
  end

  def loadFromBENCHFile(_input_file)
    if File.exist?(_input_file)
      File.open(_input_file).each do |line|
        $stderr.print "processing line #{line}"
        if not line.include?("#")
          if not line.include?("=")
            eval(transformLine(line))
          else
            if line.gsub(/\s+/, "") != ""
              tmp_line = line.split("=")
              left = transformLine(tmp_line[0])
              right = transformLine(tmp_line[1])
              if not line.include?("DFF") or not line.include?("BUFF")
                gate = Clause.new(left, right, self)
                gate.id = add_variable(gate.id)
                gate.orig_inputs = Array.new()
                gate.orig_clause = "#{left} = #{right} | #{line.gsub(/\s+/, "")}"
                gate.inputs.each do |input|
                  gate.orig_inputs.push(input)
                end
                @clauses[gate.id]= gate
              end
            else
              line = "INPUT(#{transformLine(line.split("=")[0])})"
              eval(line)
            end
          end
        end
      end
      addClauseToOrpanOutput()
      #removeInputsNotIncludedInClauses()

      id =@var_list.max*200000+1
      if @outputs.size > 1
        clause = "OR(" + @outputs.join(",") +")"
      else
        clause = "OR(" + @outputs[0].to_s + ")"
      end


      self.OUTPUT(id)
      gate = Clause.new(id, clause, self)
      gate.null_function = true
      @clauses[gate.id] = gate
      gate.orig_inputs = Array.new(gate.inputs)

      $stderr.print "calculating DFSoutput .."
      #self.calcDFSOutput()


    end
  end
end
