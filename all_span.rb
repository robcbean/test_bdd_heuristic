
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//force.rb"




def calculateAllClauseSPAN(_function,_variables,_sorted_variables)

  if calcPowerSpan?
    ret = 0.0
  else
    ret = 0
  end

  intersects = calcIntersections(_function)
  #print "intersects:#{intersects}\n"
  intersects.keys.each do |clause|
    intersect_clauses = intersects[clause]
    total_variables = Array.new()
    total_variables.concat(transformVariableIndex(_function.clauses[clause].inputs,_sorted_variables))
    intersect_clauses.each do |comp_clause|
      total_variables.concat(transformVariableIndex(_function.clauses[comp_clause].inputs,_sorted_variables))
      intersects[comp_clause].delete(clause)
    end
    total_variables = total_variables.uniq().sort()
    if calcPowerSpan?
      ret  =  ret + 2**(total_variables[total_variables.size()-1]).to_f - 2**(total_variables[0]).to_f
    else
      ret  =  ret + total_variables[total_variables.size()-1] -total_variables[0]
    end
    #print "#{total_variables}\n"
  end

  return ret
end
def calcIntersections(_function)
  ret = Hash.new()
  clause_array = _function.clauses.values
  (0.._function.clauses.size-1).each do |i|
    start = i + 1
    (start.._function.clauses.size-1).each do |j|
      clause = clause_array[i]
      com_clause = clause_array[j]
      intersect = clause.inputs & com_clause.inputs
      if intersect.size !=  0 and !com_clause.null_function and !clause.null_function
        if !ret.has_key?(clause.id)
          ret[clause.id] = Array.new()
        end
        if !ret.has_key?(com_clause.id)
          ret[com_clause.id] = Array.new()
        end
        ret[com_clause.id].push(clause.id)
        ret[clause.id].push(com_clause.id)
      end
    end
  end
  return ret
end
