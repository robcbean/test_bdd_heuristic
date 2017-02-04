require "#{File.dirname(__FILE__)}//force.rb"


def order_symmetry(_function)
  $stderr.print "Initial order:#{_function.inputs.to_s}\n"
  force_order = getFORCEOrder(_function,_function.inputs)
  order = generatePermutationAccordingGroups(_function.inputs, force_order, _function.extra_info.symmetric_groups)
  $stderr.print "Symmetric order: #{order}\n"
  return order
end


def generatePermutationAccordingGroups(_variables, _permutation_variables, _symmetric_groups)

  ret = Array.new()
  permutation_variables = Array.new(_permutation_variables)


  while !permutation_variables.empty?
    variable = permutation_variables[0]
    permutation_variables.delete_at(0)
    group_number = findVariableInGroup(_symmetric_groups, variable)
    $stderr.print("Processing variable #{ret.size} of #{_permutation_variables.size}..\n")
    if group_number == -1
      ret << variable
    else
      group = _symmetric_groups[group_number]
      variable_groups = Array.new(group.variables)
      ret << variable
      variable_groups.delete_at(variable_groups.index(variable))
      while variable_groups.size > 0
        $stderr.print("Processing group #{group_number} of #{_symmetric_groups.size}..\n")
        permutation_variables.each do |permutation_variable|
          if variable_groups.include?(permutation_variable)
            ret << permutation_variable
            permutation_variables.delete_at(permutation_variables.index(permutation_variable))
            variable_groups.delete_at(variable_groups.index(permutation_variable))
          end
        end
      end
    end
  end

  return ret

end



def findVariableInGroup(_symmetric_groups, _variable)
  ret = -1
  i = 0
  while i < _symmetric_groups.length
    group = _symmetric_groups[i]
    if group.variables.include?(_variable)
      ret = i
      break
    end
    i = i + 1
  end
  return ret
end
