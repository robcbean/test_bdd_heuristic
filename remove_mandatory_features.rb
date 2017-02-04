def find_normal_parent(_feature)
  ret = _feature
  if (_feature.parent.type == :root || _feature.parent.type == :optional || _feature.parent.type == :global_child)
    ret = _feature.parent
  else
    ret = find_normal_parent(_feature.parent)
  end
  return ret
end


def add_parents(_root_node)
  _root_node.children.each do |child|
    child.parent = _root_node
    add_parents(child)
  end
end

def remove_mandatory_feature(_root_node, _changed)

  add_parents(_root_node)
  childNodes = Array.new()
  _root_node.children.each do |child|
    childNodes << child
  end
  if _root_node.type == :mandatory
    #print "found mandatory feature:#{_root_node.id}\n"
    parent = _root_node.parent
    (0..parent.children.length-1).each do |i|
      child = parent.children[i]
      if child.id == _root_node.id
        parent.children.delete_at(i)
        break
      end
    end
    _changed[_root_node.id] = parent.id
    childNodes.each do |child|
      child.parent = parent
      parent.children << child
    end
  elsif _root_node.type == :xor || _root_node.type == :or
    parent = find_normal_parent(_root_node)
    _root_node.id = parent.id
    print "test:#{_root_node.id} #{parent.id}\n"
  end
  childNodes.each do |child|
    remove_mandatory_feature(child, _changed)
  end
end
