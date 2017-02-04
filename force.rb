require "#{File.dirname(__FILE__)}//constants_and_options.rb"

class HyperEdge
  attr_accessor :name, :edge, :variables, :clause

  def initialize(_name, _edge, _variables)
    @name = _name
    @edge = _edge
    @variables = _variables
  end
end

class HyperGraph
  attr_accessor :hyperedges, :variables

  def initialize(_hyperedges, _variables)
    @hyperedges=_hyperedges
    @variables = _variables
  end

  def getHyperEdgesConectedToVertex(_vertex)
    ret = Array.new()
    @hyperedges.each do |edge|
      if edge.variables.include? _vertex
        ret << edge
      end
    end
    return ret
  end



  def calculateSPAN(_circuit, _variables, _sorted_variables)
    if calcPowerSpan?
      ret = 0.0
    else
      ret = 0
    end

    i = 0
    while i < @hyperedges.length
      edge = @hyperedges[i]
      max_variable = -1
      min_variable = _variables.length+1
      if edge.variables.length > 1
        edge.variables.each do |variable|
          var_index = _sorted_variables.find_index(variable)
          if var_index.nil?
            raise Exception.new("variable #{variable} not found in sorted variables")
          end
          if max_variable < var_index
            max_variable = var_index
          end
          if min_variable > var_index
            min_variable = var_index
          end
        end

        if calcPowerSpan?
          value = (2**(max_variable.to_f) - 2**(min_variable.to_f))
        else
          value = (max_variable - min_variable)
        end
        ret = ret + value
      end
      i = i + 1
    end


    return ret
  end

  def getVariableIndex(_variables, _sorted_variables, _variable)
    var_index = _variables.find_index(_variable)
    ret = _sorted_variables.find_index(var_index)
    return ret
  end
end


def generateHyperGraph(_function, _all_gates=true, _orig_inputs=false)
  hyperedges = Array.new()
  #_circuit.gates.values.each do |gate|
  if _all_gates
    clauses = _function.clauses.keys
  else
    clauses = _function.getDFSOrderOutputs
  end
  clauses.each do |gate_id|
    gate = _function.clauses[gate_id]
    if gate.orig_clause != ""
      if not _orig_inputs
        variables = gate.inputs
      else
        variables = gate.orig_inputs
      end

      hyperedges << HyperEdge.new(gate.id, gate.clause, variables)
    end
  end
  ret = HyperGraph.new(hyperedges, _function.inputs)
  #$stderr.print "hypergraphs #{ret.hyperedges.size}\n"
  return ret
end


def calculateCOG(_variables, _sorted_variables, _hyperedge)
  ret = 0.0
  _hyperedge.variables.each do |variable|
    perm_index = _sorted_variables.find_index(variable)
    ret = ret + perm_index
  end
  ret = ret /_hyperedge.variables.length
  return ret
end

def calcTentativeLocation(_variables,_sorted_variables, _hypergraph, _vertex)

  ret = 0.0
  edges = _hypergraph.getHyperEdgesConectedToVertex(_vertex)
  edges.each do |edge|
    cog = calculateCOG(_variables,_sorted_variables,edge)
    ret = ret + cog
  end
  if edges.length != 0
    ret = ret  / edges.length
  end

  return ret

end

def findVariableInGroup(_symmetric_groups, _variable)
  ret = -1
  i = 0
  while i < _symmetric_groups.groups.length
    group = _symmetric_groups.groups[i]
    if group.variables.include?(_variable.to_sym)
      ret = i
      break
    end
    i = i + 1
  end
  return ret
end

def getFORCEOrder(_circuit,_sorted_variables = nil )

  hypergraph = generateHyperGraph(_circuit, false, false)
  sorted_variables = Array.new()

  dfs_output = _circuit.getDFSOrderInputs(true)
  dfs_output.each do |variable|
    sorted_variables.push(variable)
  end
  if not _sorted_variables.nil?
    tmp_array = Array.new()
    sorted_variables = Array.new()
    _sorted_variables.each do |variable|
      if dfs_output.include?(variable)
        tmp_array << variable
        sorted_variables << variable
      end
    end
    dfs_output = tmp_array
  end

  ospan = 1000000000000000

  cspan = hypergraph.calculateSPAN(_circuit, dfs_output, sorted_variables)


  while cspan < ospan
    new_locations = Hash.new()
    dfs_output.each do |variable|
      new_locations[variable] = calcTentativeLocation(dfs_output, sorted_variables, hypergraph, variable)
    end
    prev_sorted_variables = Array.new(sorted_variables)
    sorted_variables = Array.new()
    i = 0
    #$stderr.print "size old:#{prev_sorted_variables.size}\n"
    new_locations.sort_by { |variable, location| location }.each do |new_location|
      variable = new_location[0]
      sorted_variables[i] = variable
      i = i + 1
    end
    #$stderr.print "size new:#{sorted_variables.size}\n"
    ospan = cspan
    cspan = hypergraph.calculateSPAN(_circuit, dfs_output, sorted_variables)
    #$stderr.print "old: #{ospan} new :#{cspan}\n"
  end


  return prev_sorted_variables

end

