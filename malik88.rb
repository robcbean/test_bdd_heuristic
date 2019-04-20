def get_fanouts(_function, _n)
  ret = Array.new()
  _function.dfs_outputs.each do |gate_id|
    gate = _function.clauses[gate_id]
    if gate.orig_inputs.include?(_n)
      ret.push(gate.id)
    end
  end
  return ret
end

def get_fanins(_function, _n)
  ret = Array.new()
  if _function.dfs_outputs.include?(_n)
    ret = _function.clauses[_n].inputs
  end
  return ret
end


def compute_level(_circuit, _gate, _levels, _descendents)
  ret = 0
  if not _levels.keys.include?(_gate)
    _descendents.call(_circuit, _gate).each do |fanout|
      tmp = compute_level(_circuit, fanout, _levels, _descendents)
      if tmp > ret
        ret = tmp
      end
    end
    ret = ret + 1
    if not _levels.keys.include?(_gate)
      _levels[_gate] = ret
    else
      if ret > _levels[_gate]
        _levels[_gate] = ret
      end
    end
  else
    ret = _levels[_gate]
  end
  return ret
end

def malik88level(_circuit)
  ret = Array.new()
  levels = Hash.new()
  inputs = _circuit.getDFSOrderInputs
  #_function.gates.each_value do |gate|
  inputs.each do |input|
    compute_level(_circuit, input, levels, method(:get_fanouts))
  end
  levels.sort { |a, b| b[1] <=> a[1] }.each do |input|
    if inputs.include?(input[0])
      if not ret.include?(input[0])
        ret.push(input[0])
      end
    end
  end
  return ret
end


def malik88fanin(_circuit)
  $order_list = Array.new()
  n = find_last_output(_circuit)
  makeMalik88FaninOrder(_circuit, n)
  return $order_list.reject{|c| not _circuit.inputs.include?(c)}
end


def makeMalik88FaninOrder(_circuit, _n)

  if not $order_list.include?(_n)

    #if not $order_list.include?(_n) and _circuit.inputs.include?(_n)
    $order_list.push(_n)
    #end

    if _circuit.clauses.include?(_n)
      levels = Hash.new()

      _circuit.clauses[_n].inputs.each do |fanin|
        compute_level(_circuit, fanin, levels, method(:get_fanins))
      end

      _sort_levels = levels.sort { |a, b| b[1] <=> a[1] }

      if _circuit.clauses.keys.include?(_n)
        _sort_levels.each do |input|
          if _circuit.clauses[_n].inputs.include?(input[0])
            makeMalik88FaninOrder(_circuit, input[0])
          end
        end
      end

    end


  end

end


