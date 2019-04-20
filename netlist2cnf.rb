require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"



def clause_to_pbl(_clause)
  ret = _clause.gsub("[", "")
  ret = ret.gsub("]", "")
  ret = ret.gsub("!", "~")
end

def pbl_to_clause(_clause)
  ret = _clause.gsub("~", "!")
  ret = ret.gsub(/[[:digit:]]+/) { |s| "[#{s}]" }
  return ret
end

def generate_var_order(_circuit)
  ret = ""
  _circuit.inputs.each do |input|
    if ret != ""
      ret = "#{ret} "
    end
    ret = "#{ret}x#{variable_index(_circuit.var_list, input)}"
  end
  return ret
end


def pbl_to_nne(_circuit, _clause)
  output_pbl = clause_to_pbl(_clause)
  circuit = _circuit

  File.open("pbl_to_nne.txt", "w+") { |f|
    render = ERB.new(File.new("clause2pbl.erb").read())
    f.write(render.result(binding))

  }
  cnf = `tocnf/transform_to_nne.py pbl_to_nne.txt`
  ret = pbl_to_clause(cnf).gsub(/\s+/, "")
  return ret
end


def netlist2cnf(_circuit)

  circuit = _circuit
  main_expr = _circuit.outputs[_circuit.output.size-1]

  File.open("clause.txt", "w+") { |f|
    render = ERB.new(File.new("clause2pbl_all.erb").read())
    f.write(render.result(binding))
  }


  # _circuit.gates.values.each do |gate|
  #   print "convert clauses before #{variable_name(_circuit.var_list,gate.id)}: #{gate.ex_clause}\n"
  #   gate.ex_clause = pbl_to_cnf(_circuit,gate.ex_clause)
  #   print "convert clauses after #{variable_name(_circuit.var_list,gate.id)} :#{gate.ex_clause}\n"
  # end
  #
  #
  #  _circuit.gates.values.each do |gate|
  #    print "expand clause before:#{gate.ex_clause}\n"
  #    expand_clause(_circuit,gate)
  #    print "expand clause after:#{gate.ex_clause}\n"
  #  end


end
