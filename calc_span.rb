require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//force.rb"
require "#{File.dirname(__FILE__)}//parse_def.rb"
require "#{File.dirname(__FILE__)}//complexity.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require "#{File.dirname(__FILE__)}//all_span.rb"
require "#{File.dirname(__FILE__)}//new_span.rb"

def calcSpanAndComplexity(_function, _heuristics)
  hypergraph = generateHyperGraph(_function, false, false)
  ret = Hash.new()
  _heuristics.each do |heur|
    if not heur.order.nil?
      $stderr.print "calculating span #{heur.name}  #{heur.order.size} #{heur.expanded} ...\n"
      span = hypergraph.calculateSPAN(_function, _function.var_list, heur.order)
      if calcComplexity? or calcAllSpan? or calcNewSpan?
        if calcComplexity?
          complexity = calcComplexity(_function, heur.order)
        else
          if calcNewSpan?
	    complexity = calcNEWSPAN(_function,_function.inputs,heur.order)
	  else
            complexity = calculateAllClauseSPAN(_function,_function.inputs,heur.order)  + span
          end
        end
        ret[heur.name] = "#{span}\t#{complexity}"
      else
        ret[heur.name] = span
      end
      $stderr.print "heuristic:#{heur.name} span:#{span}\n"
    end
  end
  return ret

end
