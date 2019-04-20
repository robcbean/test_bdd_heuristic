class IdGenerator
  attr_accessor :current

  def initialize(_start=0)
    @current = 0
  end

  def next_id()

    ret = @current
    @current = @current + 1
    return ret

  end

end