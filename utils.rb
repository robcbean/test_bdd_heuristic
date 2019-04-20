def find_last_output(_circuit)
  ret = -1
  _circuit.clauses.each_value do |gate|
    if gate.null_function
      ret = gate.id
    end
  end
  if ret == -1
    ret = _circuit.outputs[_circuit.outputs.size-1]
  end
  return ret
end


def variable_index(_var_list, _id)
  ret = _var_list.find_index(_id)
  return ret
end

def variable_name(_var_list, _id)
  ret = "x[#{_var_list.find_index(_id)}]"
  return ret
end


def isConnectedToPrimaryInput(_circuit, _variable)
  ret = false
  if _circuit.inputs.include?(_variable)
    ret = true
  end
  return ret
end


def transformVariableIndex(_variables,_sorted_variables)
  ret = Array.new()
  _variables.each do |variable|
    ret << _sorted_variables.find_index(variable)
  end
  return ret
end



def first_variable_group(_variables,_symmetric_group)

  ret  = -1
  tmp_var = Array.new
  $stderr.print "Finding variables in group #{_symmetric_group.variables.to_s}\n"
  _symmetric_group.variables.each do |element|
    if _variables.index(element) != nil
      tmp_var << _variables.index(element)
    end
  end
  tmp_var.sort!
  ret = tmp_var[0]
  return ret

end


