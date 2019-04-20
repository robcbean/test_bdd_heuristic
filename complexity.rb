require 'descriptive-statistics'

def getMinClause(_function, _order, _clause)
  stat = DescriptiveStatistics::Stats.new(transformInputs(_clause.inputs, _order))
  if stat.min.nil?
    print "hay"
  end
  ret = stat.min * _function.clauses.size + stat.max
  return ret
end

def getClauseKey(_clause_1, _clause_2)
  if _clause_1.id > _clause_2.id
    ret = "#{_clause_1.id}-#{_clause_2.id}"
  else
    ret = "#{_clause_2.id}-#{_clause_1.id}"
  end
end

def transformInputs(_inputs, _order)
  ret = Array.new()
  _inputs.each do |input|
    ret << _order.find_index(input)
  end
  return ret
end

def calcComplexity(_function, _order)
  ret = 0.0
  prev = Hash.new()
  _function.clauses.values.select { |clause| not extraClause(clause.inputs, _function) }.sort_by { |clause| getMinClause(_function, _order, clause) }.to_a.each do |clause_1|
    inputs1 = transformInputs(clause_1.inputs, _order)
    stat1 = DescriptiveStatistics::Stats.new(inputs1)
    _function.clauses.values.select { |clause| not extraClause(clause.inputs, _function) }.sort_by { |clausev2| getMinClause(_function, _order, clausev2) }.to_a.each do |clause_2|
      inputs2 = transformInputs(clause_2.inputs, _order)
      if not prev.has_key?(getClauseKey(clause_1, clause_2)) and clause_1.id != clause_2.id
        stat2 = DescriptiveStatistics::Stats.new(clause_2.inputs)
        prev[getClauseKey(clause_1, clause_2)] = true
        #print "#{stat1.max}\t#{stat1.min}\t#{stat2.max}\t#{stat2.min}\n"
        #stat1: [2,3] stat2: [1,4] 2-3
        if stat1.min <= stat2.min and stat2.max <= stat1.max
          #print "included: [#{stat1.min}[#{stat2.min},#{stat2.max}]#{stat1.max}]\n"
          ret = ret + stat1.max - stat1.min
          #stat1 [3,7] stat2: [1,5]  5-3
        elsif stat1.min <= stat2.max and stat1.max >= stat2.max
          #print "upper: [#{stat1.min}[#{stat2.min},#{stat2.max}]#{stat1.max}]\n"
          ret = ret + stat2.max - stat1.min
          #stat1 [1,4] #stat 2 [3,8] 4 - 3
        elsif stat1.min <= stat2.min and stat1.max <= stat2.max and stat1.max >= stat2.min
          #print "lower: [#{stat1.min}[#{stat2.min},#{stat2.max}]#{stat1.max}]\n"
          ret = ret + stat1.max - stat2.min
        else
          #print "disjoint: [#{stat1.min},#{stat1.max}],[#{stat2.min},#{stat2.max}]\n"
        end
      end
    end
  end

  return ret

end