class Bool
  # to_s for binary operators
  def to_s(lhs, rhs, operator)
    if operator == '=>'
      "not (#{lhs.to_s}) or (#{rhs.to_s})"
    elsif operator == '<=>'
      "(not (#{lhs.to_s}) or (#{rhs.to_s})) and (not (#{rhs.to_s}) or (#{lhs.to_s}))"
    else
      "(#{lhs.to_s}) #{operator} (#{rhs.to_s})"
    end
  end

  #to_s

  def get_literals(lhs, rhs)
    (@lhs.get_literals + @rhs.get_literals).uniq
  end

  #def get_literals
  attr_accessor :visited
end #Bool

class True < Bool
  attr_accessor :value

  def initialize(value)
    @value = value
  end

  def to_s
    @value
  end

  def get_literals
    [@value]
  end
end #Lit

class Lit < Bool
  attr_accessor :value

  def initialize(value)
    @value = value
  end

  def to_s
    @value
  end

  def get_literals
    [@value]
  end
end #Lit

class And < Bool
  attr_accessor :lhs, :rhs

  def initialize(lhs, rhs)
    @lhs = lhs
    @rhs = rhs
  end

  def to_s
    super(@lhs, @rhs, 'and')
  end

  #to_s

  def get_literals
    super(@lhs, @rhs)
  end

end #And

class Or < Bool
  attr_accessor :lhs, :rhs

  def initialize(lhs, rhs)
    @lhs = lhs
    @rhs = rhs
  end

  def to_s
    super(@lhs, @rhs, 'or')
  end

  #to_s

  def get_literals
    super(@lhs, @rhs)
  end

end #Or

class Implication < Bool
  attr_accessor :lhs, :rhs

  def initialize(lhs, rhs)
    @lhs = lhs
    @rhs = rhs
  end

  def to_s
    super(@lhs, @rhs, '=>')
  end

  #to_s

  def get_literals
    super(@lhs, @rhs)
  end

end #Implication

class DoubleImplication < Bool
  attr_accessor :lhs, :rhs

  def initialize(lhs, rhs)
    @lhs = lhs
    @rhs = rhs
  end

  def to_s
    super(@lhs, @rhs, '<=>')
  end

  #to_s

  def get_literals
    super(@lhs, @rhs)
  end

end #DoubleImplication

class Not < Bool
  attr_accessor :rhs

  def initialize(rhs)
    @rhs = rhs
  end

  def to_s
    "not (#{@rhs.to_s})"
  end

  def get_literals
    @rhs.get_literals
  end

end #Not

def eval_bool(bool, truth_assignments)
  if truth_assignments.length != bool.get_literals.length
    die("I cannot evaluate #{bool} against values #{truth_assignments}")
  else
    bool_expression = bool.to_s
    truth_assignments.each { |literal, value|
      bool_expression.gsub!(/\b#{literal}\b/, value)
    }
    return eval(bool_expression)
  end
end #eval_bool