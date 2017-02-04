class FUNCTION
  def loadFromDIMACSFile(_input_file)
    if File.exists?(_input_file)
      n_clauses = 0
      File.open(_input_file).each do |line|
        if not line.include?("c") and not line.include?("p") and line.gsub(/\s+/, "") != ""
          add_variable(n_clauses)
          gate = Clause.new(n_clauses, "", self)
          processDIMACSClause(gate, line)
          n_clauses = n_clauses + 1
          @clauses[gate.id] = gate
        elsif line.include?("p")
          n_clauses = line.split()[2].to_i + 1
        end
      end
      #self.calcDFSOutput()
    end
  end

  def processDIMACSClause(_gate, _clause)
    _gate.clause = ""
    add_output(_gate.id)
    _clause.split().each do |variable|
      var = variable.to_i
      if var != 0
        variable = add_variable(var.abs)
        add_input(var.abs)
        _gate.inputs.push(var.abs)
        if _gate.clause != ""
          _gate.clause = "#{_gate.clause} | "
        end
        if var > 0
          _gate.clause = "#{_gate.clause} #{variable_name(@inputs, var)}"
        else
          _gate.clause = "#{_gate.clause} !#{variable_name(@inputs, var.abs)}"
        end
      end
    end
    _gate.ex_clause = _gate.clause
  end
end 
