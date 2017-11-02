require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"


def generatePreorderRandom(_function, _percent)

  random_features = (_function.inputs.size  * _percent/200).ceil.to_i * 2
  preorder = _function.getDFSOrderInputs(true)

  change_values = preorder.sample(random_features)
  ret = preorder.clone

  (0..(random_features/2-1)).to_a.each do |j|

    index_var1 = preorder.find_index(change_values[j*2])
    index_var2 = preorder.find_index(change_values[j*2+1])

    ret[index_var2] = change_values[j*2]
    ret[index_var1] = change_values[j*2+1]
  end

  return ret

end