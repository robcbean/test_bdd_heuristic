require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//force.rb"


def calcNEWSPAN(_function,_variables,_sorted_variables)

	ret = 0
	
	totspan = Array.new(_variables.size,0)
	_function.clauses.values.each do |clause|
		inputs  = transformVariableIndex(clause.inputs,_sorted_variables)		
		max = inputs.max
		min = inputs.min
		(min..max).each do |i|
			totspan[i] = totspan[i] + 1
		end
	end
	
	(0.._variables.size-1).each do |i|
		ret = ret + totspan[i] * (i+1)
	end

	return ret

	
end
