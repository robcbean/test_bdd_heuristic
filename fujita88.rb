def isConnectedMoreThanOneGate(_circuit, _variable)
  ret = false
  i = 0
  _circuit.clauses.each_value do |gate|
    if gate.inputs.include?(_variable)
      i = i + 1
    end
  end
  if i > 1
    ret = true
  end
  return ret
end


def makeOrderFujita88(_circuit, _n)
  ret = Array.new
  gate = _circuit.clauses[_n]
  gate.inputs.each do |i|
    if not $mark.include?(i)
      if isConnectedToPrimaryInput(_circuit, i)
        if isConnectedMoreThanOneGate(_circuit, i)
          $fanout2up = Array.new()
          $fanout2up.push(i)
          if not $order.include?(i)
            $order.push(i)
          end
        else
          $fanout1list.push(i)
        end
      else
        makeOrderFujita88(_circuit, i)
      end
    end
  end
  if $fanout2up.size > 0
    if $fanout1list.size > 0
      index = $order.find_index($fanout2up[0])
      if index.nil?
        $fanout1list.each do |variable|
          $order.push(variable)
        end
      else
        index = index + 1
        $fanout1list.each do |variable|
          $order.insert(index, variable)
          index = index + 1
        end
      end
    end
    $fanout1list.clear
  else
    $fanout1list.each do |variable|
      $order.push(variable)
    end
    $fanout1list.clear
  end

  $mark.push(_n)
  if $order.size() == 0
    return $fanout1list
  else
    return $order
  end

end


def init_variables()
  $mark = Array.new()
  $fanout2up = Array.new()
  $fanout1list = Array.new()
  $order = Array.new()
end


def fujita88(_circuit)
  init_variables()
  n = find_last_output(_circuit)
  ret = makeOrderFujita88(_circuit, n)
  return ret
end
