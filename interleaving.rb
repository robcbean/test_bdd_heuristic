def order_clause(_circuit, _gate_id, _output_id)
  #print "output: #{_output_id} last: #{$last} gate_id: #{_gate_id} vl:#{$vl} before start\n"
  if $processed.include?(_gate_id)
    if _gate_id != _output_id
      $last = _gate_id
      $from[_gate_id] = _output_id
    end
    return
  end
  $processed.push(_gate_id)
  $from[_gate_id] = _output_id
  if _circuit.clauses.keys.include?(_gate_id)
    clause = _circuit.clauses[_gate_id]
    clause.inputs.each do |input|
      order_clause(_circuit, input, _output_id)
    end
  end
  #print "last: #{$last} gate_id: #{_gate_id} vl:#{$vl} before\n"
  if $last.nil?
    $vl.unshift(_gate_id)
  else
    if $last.size == 1
      $vl.push(_gate_id)
    else
      index = $vl.find_index($last)
      $vl.insert(index+1, _gate_id)
    end
  end
  #print "last: #{$last} gate_id: #{_gate_id} vl:#{$vl} after\n"
  $last = _gate_id

end


def getFuji1993(_circuit)
  $vl = Array.new()
  $from = Hash.new()
  $processed = Array.new()
  _circuit.outputs.each do |output_id|
    $last = nil
    order_clause(_circuit, output_id, output_id)
  end
  ret = Array.new($vl)
  $vl.each do |variable|
    if not _circuit.inputs.include?(variable)
      ret.delete(variable)
    end
  end
  return ret
end
