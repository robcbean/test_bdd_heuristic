require "#{File.dirname(__FILE__)}//bool.rb"
require "#{File.dirname(__FILE__)}//bool_parser.tab.rb"

#require 'rational'
#require 'mathn'

#@@dot_font = 'Lucida Bright'
#@@dot_header = "digraph bdd {
#\tgraph [fontname = \"#{@@dot_font}\"];
#\tnode [fontname = \"#{@@dot_font}\"];
#\tedge [fontname = \"#{@@dot_font}\"];\n"

$steps_rec = 0
$steps_it = 0

class Vertex
  attr_accessor :index, :low, :high, :mark
  attr_accessor :prob_high, :prob_low # to paint the bdd computations

  def initialize(index, low, high)
    @index = index
    @low = low
    @high = high
    @mark = false
  end

  #initialize

  def ==(bdd)
    return (@index == bdd.index) &&
        (@low == bdd.low) &&
        (@high == bdd.high)
  end

  def to_s
    "Vertex '#{@index}': low = #{@low}; high = #{@high} "
  end

end #Vertex

class BDD
  attr_accessor :bdd, :bdd_length, :bool, :var_ordering

  def initialize(formula, var_ordering)
    bool_parser = BoolParser.new(:Lexer)
    @bool = bool_parser.parse(formula)
    @bdd = Array.new()
    @bdd[0] = Vertex.new(bool.get_literals().length(), nil, nil)
    @bdd[1] = @bdd[0]
    @bdd_length = 2
    @var_ordering = var_ordering
  end

  #initialize

  def lookup(bdd)
    i = 2
    found = false
    while !found && i<@bdd_length
      if @bdd[i] == bdd
        found = true
      else
        i += 1
      end
    end
    if found
      return i
    else
      return 0
    end
  end

  #lookup

  def mk(bdd)
    if bdd.low == bdd.high
      return bdd.low
    else
      i = lookup(bdd)
      if i!=0 #found
        return i
      else
        @bdd[@bdd_length] = bdd
        @bdd_length += 1
        return @bdd_length-1
      end
    end
  end

  #mk

  def build()

    def build_aux(truth_assignments, i)
      if i==(@bool.get_literals().length())
        if eval_bool(@bool, truth_assignments)
          return 1
        else
          return 0
        end
      else
        truth_assignments_0 = truth_assignments.dup
        truth_assignments_0[@var_ordering[i]] = 'false'
        v0 = build_aux(truth_assignments_0, i+1)
        truth_assignments_1 = truth_assignments.dup
        truth_assignments_1[@var_ordering[i]] = 'true'
        v1 = build_aux(truth_assignments_1, i+1)
        bdd = Vertex.new(i, v0, v1)
        return mk(bdd)
      end
    end

    build_aux(Hash.new(), 0)
  end

  def to_s
    puts "v0: 0"
    puts "v1: 1"
    i = 2
    while i < @bdd_length
      v = @bdd[i]
      puts "v#{i}: index=#{v.index} (#{@var_ordering[v.index]}), low=#{v.low}, high=#{v.high}"
      i += 1
    end
  end

  def to_dot()
    dot_code = @@dot_header
    dot_code += "\tv0 [label=\"0\", shape=box];\n"
    dot_code += "\tv1 [label=\"1\", shape=box];\n"
    i = 2
    while i < @bdd_length
      v = @bdd[i]

      dot_code += "\tv#{i} [margin=0,label=<<TABLE BORDER=\"0\"><TR><TD><B>#{@var_ordering[v.index]}</B>, <I>v#{i}</I></TD></TR></TABLE>>];\n"
      dot_code += "\tv#{i} -> v#{v.low} [style=dotted, arrowhead=none];\n"
      dot_code += "\tv#{i} -> v#{v.high} [arrowhead=none];\n"
      i += 1
    end
    dot_code += '}'
    return dot_code
  end

  #to_dot

  def sat_count()
    def count(u)
      if u == 0
        res = 0
      elsif u == 1
        res = 1
      else
        res = 2**(@bdd[@bdd[u].low].index - @bdd[u].index - 1) *
            count(@bdd[u].low) +
            2**(@bdd[@bdd[u].high].index - @bdd[u].index - 1) *
                count(@bdd[u].high)
      end
      return res
    end

    if @bdd_length == 2 # just 0 and 1 nodes
      return 0
    else
      return count(@bdd_length-1)
    end
  end

  def get_formula_sat_prob()
    formula_sat_prob = Array.new(@bdd_length, 0)
    #formula_sat_prob[@bdd_length-1] = 1.0
    formula_sat_prob[@bdd_length-1] = Rational(1)
    i = @bdd_length-1
    while i>1 # for each non-terminal node
      formula_sat_prob[@bdd[i].low] += formula_sat_prob[i]/2.0
      formula_sat_prob[@bdd[i].high] += formula_sat_prob[i]/2.0
      i -= 1
    end
    return formula_sat_prob

    # sat-count is formula_sat_prob[1] * 2^(number_of_vars)
    #return (formula_sat_prob[i]) * (2**@var_ordering.length)
  end

  #get_formula_sat_prob

  def unmark!()
    @bdd.each do |vertex|
      vertex.mark = false
    end
  end

  def get_prob()

    def get_marginal_prob(v, total_prob,
                          formula_sat_prob, prob)
      puts "begin v = #{v} =============="
      aux = @bdd[v]
      puts "variable = #{@var_ordering[aux.index]}"
      $steps_rec += 1


      #dot_code += "\tv#{i} [label=<<p>#{@var_ordering[v.index]}</p><p style=\"font-size:smaller;\">formula_sat_prob=#{formula_sat_prob[i]}</p><p style=\"font-size:smaller;\">prob_low=#{v.prob_low}</p><p style=\"font-size:smaller;\">prob_high=#{v.prob_high}</p><p style=\"font-size:smaller;\">marginal_prob=#{marginal_prob[v.index]}</p><p style=\"font-size:smaller;\">prob=#{prob[v.index]}</p>>];\n"
      #dot_code += "\tv#{i} [label=\"#{@var_ordering[v.index]}\\nformula_sat_prob=#{formula_sat_prob[i]}\\nprob_low=#{v.prob_low}\\nprob_high=#{v.prob_high}\\nmarginal_prob=#{marginal_prob[v.index]}\\nprob=#{prob[v.index]}\"];\n"


      #puts @var_ordering[v]

      prob_low = 0
      prob_high = 0
      @bdd[v].mark = !@bdd[v].mark
      if @bdd[v].low == 1
        prob_low = formula_sat_prob[v]/2.0
      elsif @bdd[v].low != 0
        if !(@bdd[v].low).nil? and (@bdd[v].mark != @bdd[@bdd[v].low].mark)
          get_marginal_prob(@bdd[v].low, total_prob,
                            formula_sat_prob, prob)
        end
        prob_low = (total_prob[@bdd[v].low]*(formula_sat_prob[v])/2.0) /
            (formula_sat_prob[@bdd[v].low])
      end
      if @bdd[v].high == 1
        prob_high = formula_sat_prob[v]/2.0
      elsif @bdd[v].high != 0
        if @bdd[v].mark != @bdd[@bdd[v].high].mark
          get_marginal_prob(@bdd[v].high, total_prob,
                            formula_sat_prob, prob)
        end
        prob_high = (total_prob[@bdd[v].high]*(formula_sat_prob[v])/2.0) /
            (formula_sat_prob[@bdd[v].high])
      end
      total_prob[v] = prob_low + prob_high
      prob[@bdd[v].index] += prob_high
      i = @bdd[v].index + 1


      while (i<@bdd[@bdd[v].low].index)

        puts "v= #{v}"
        aux = @bdd[v]
        puts "variable = #{@var_ordering[aux.index]}"
        puts "low, i = #{i}, #{@var_ordering[i]}"
        $steps_it += 1


        prob[i] += prob_low/2.0
        i +=1
      end
      i = @bdd[v].index + 1
      while (i<@bdd[@bdd[v].high].index)

        puts "v= #{v}"
        aux = @bdd[v]
        puts "variable = #{@var_ordering[aux.index]}"
        puts "high, i = #{i}, #{@var_ordering[i]}"
        $steps_it += 1

        prob[i] += prob_high/2.0
        i +=1
      end
      puts "end v = #{v} =============="
    end

    #get_marginal_prob

    total_prob = Array.new(@bdd_length, 0)
    prob = Array.new(var_ordering.length(), 0)
    formula_sat_prob = get_formula_sat_prob()
    get_marginal_prob(@bdd_length-1, total_prob,
                      formula_sat_prob, prob)
    for i in 0..(var_ordering.length()-1)
      prob[i] = prob[i]/formula_sat_prob[1]
    end
    return prob
  end

  #get_prob

  def get_prob_dot()

    def get_marginal_prob(u, total_prob,
                          marginal_prob, formula_sat_prob)
      prob_low = 0
      prob_high = 0
      @bdd[u].mark = !@bdd[u].mark
      if @bdd[u].low == 1
        prob_low = formula_sat_prob[u]/2.0
      elsif @bdd[u].low != 0
        if @bdd[u].mark != @bdd[@bdd[u].low].mark
          get_marginal_prob(@bdd[u].low, total_prob,
                            marginal_prob, formula_sat_prob)
        end
        prob_low = (total_prob[@bdd[u].low]*(formula_sat_prob[u])/2.0) /
            (formula_sat_prob[@bdd[u].low])
      end
      if @bdd[u].high == 1
        prob_high = formula_sat_prob[u]/2.0
      elsif @bdd[u].high != 0
        if @bdd[u].mark != @bdd[@bdd[u].high].mark
          get_marginal_prob(@bdd[u].high, total_prob,
                            marginal_prob, formula_sat_prob)
        end
        prob_high = (total_prob[@bdd[u].high]*(formula_sat_prob[u])/2.0) /
            (formula_sat_prob[@bdd[u].high])
      end
      total_prob[u] = prob_low + prob_high
      marginal_prob[@bdd[u].index] += prob_high
      i = @bdd[u].index + 1
      while (i<@bdd[@bdd[u].low].index)
        marginal_prob[i] += prob_low/2.0
        i +=1
      end
      i = @bdd[u].index + 1
      while (i<@bdd[@bdd[u].high].index)
        marginal_prob[i] += prob_high/2.0
        i +=1
      end

      @bdd[u].prob_low = prob_low
      @bdd[u].prob_high = prob_high
    end

    #get_marginal_prob

    total_prob = Array.new(@bdd_length, 0)
    formula_sat_prob = get_formula_sat_prob()
    marginal_prob = Array.new(var_ordering.length(), 0)
    prob = Array.new(var_ordering.length(), 0)
    get_marginal_prob(@bdd_length-1, total_prob,
                      marginal_prob, formula_sat_prob)
    for i in 0..(var_ordering.length()-1)
      prob[i] = marginal_prob[i]/formula_sat_prob[1]
    end

    dot_code = @@dot_header
    dot_code += "\tv0 [label=\"0\\nformula_sat_prob=#{formula_sat_prob[0]}\", shape=box];\n"
    dot_code += "\tv1 [label=\"1\\nformula_sat_prob=#{formula_sat_prob[1]}\", shape=box];\n"
    i = 2
    while i < @bdd_length
      v = @bdd[i]
      #dot_code += "\tv#{i} [label=<<p>#{@var_ordering[v.index]}</p><p style=\"font-size:smaller;\">formula_sat_prob=#{formula_sat_prob[i]}</p><p style=\"font-size:smaller;\">prob_low=#{v.prob_low}</p><p style=\"font-size:smaller;\">prob_high=#{v.prob_high}</p><p style=\"font-size:smaller;\">marginal_prob=#{marginal_prob[v.index]}</p><p style=\"font-size:smaller;\">prob=#{prob[v.index]}</p>>];\n"
      #dot_code += "\tv#{i} [label=\"#{@var_ordering[v.index]}\\nformula_sat_prob=#{formula_sat_prob[i]}\\nprob_low=#{v.prob_low}\\nprob_high=#{v.prob_high}\\nmarginal_prob=#{marginal_prob[v.index]}\\nprob=#{prob[v.index]}\"];\n"
      dot_code += "\tv#{i} [margin=0,label=<<TABLE BORDER=\"0\"><TR><TD><B>#{@var_ordering[v.index]}</B>, <I>v#{i}</I></TD></TR><TR><TD ALIGN=\"LEFT\" SIZE=\"2\">formula_sat_prob=#{formula_sat_prob[i]}</TD></TR><TR><TD ALIGN=\"LEFT\">prob_low=#{v.prob_low}, prob_high=#{v.prob_high}</TD></TR><TR><TD ALIGN=\"LEFT\">marginal_prob=#{marginal_prob[v.index]}, prob=#{prob[v.index]}</TD></TR></TABLE>>];\n"
      dot_code += "\tv#{i} -> v#{v.low} [style=dotted, arrowhead=none];\n"
      dot_code += "\tv#{i} -> v#{v.high} [arrowhead=none];\n"
      i += 1
    end
    dot_code += '}'
    return dot_code
  end

  #get_prob_dot


  def pour_water_dot()
    formula_sat_prob = get_formula_sat_prob()
    dot_code = @@dot_header
    dot_code += "\tv0 [label=\"0\\nformula_sat_prob=#{formula_sat_prob[0]}\", shape=box];\n"
    dot_code += "\tv1 [label=\"1\\nformula_sat_prob=#{formula_sat_prob[1]}\", shape=box];\n"
    i = 2
    while i < @bdd_length
      v = @bdd[i]
      dot_code += "\tv#{i} [label=\"#{@var_ordering[v.index]}\\nformula_sat_prob=#{formula_sat_prob[i]}\"];\n"
      dot_code += "\tv#{i} -> v#{v.low} [style=dotted, arrowhead=none];\n"
      dot_code += "\tv#{i} -> v#{v.high} [arrowhead=none];\n"
      i += 1
    end
    dot_code += '}'
    return dot_code
  end

  #pour_water_dot

  def does_it_reach_one?(v, through_high_array, through_low_array)

    def update_reduced_vertices(v, direction, through_high_array, through_low_array)
      if direction == :high
        ((@bdd[v].index+1)..(@bdd[@bdd[v].high].index-1)).each do |i|
          through_high_array[i] = true
          through_low_array[i] = true
        end
      else # direction == :low
        ((@bdd[v].index+1)..@bdd[@bdd[v].low].index-1).each do |i|
          through_high_array[i] = true
          through_low_array[i] = true
        end
      end
    end


    puts "does_it_reach_one?(#{v})"

    if (!@bdd[v].mark)
      through_high = false
      through_low = false
      @bdd[v].mark = true
      if @bdd[v].high == 1
        puts "por h1"
        through_high_array[@bdd[v].index] = true
        through_high = true
        update_reduced_vertices(v, :high, through_high_array, through_low_array)
      elsif @bdd[v].high != 0
        puts "por h2"
        through_high = does_it_reach_one?(@bdd[v].high, through_high_array, through_low_array)
        puts "comming back to #{v} from h2"
        if through_high
          through_high_array[@bdd[v].index] = true
          update_reduced_vertices(v, :high, through_high_array, through_low_array)
        end
      end
      if @bdd[v].low == 1
        puts "por l1"
        through_low_array[@bdd[v].index] = true
        through_low = true
        update_reduced_vertices(v, :low, through_high_array, through_low_array)
      elsif @bdd[v].low != 0
        puts "por l2"
        through_low = does_it_reach_one?(@bdd[v].low, through_high_array, through_low_array)
        puts "comming back to #{v} from l2"
        if through_low
          through_low_array[@bdd[v].index] = true
          update_reduced_vertices(v, :low, through_high_array, through_low_array)
        end
      end
    else
      through_high = through_high_array[@bdd[v].index]
      through_low = through_low_array[@bdd[v].index]
    end
    p through_high_array
    p through_low_array
    return (through_high or through_low)

  end

  def get_core_and_dead()
    through_high_array = Array.new(var_ordering.length, false)
    through_low_array = Array.new(var_ordering.length, false)
    core = Array.new
    dead = Array.new
    does_it_reach_one?(bdd_length-1, through_high_array, through_low_array)
    (0..var_ordering.length-1).each do |i|
      if through_high_array[i] and !through_low_array[i]
        core << var_ordering[i]
      elsif !through_high_array[i] and through_low_array[i]
        dead << var_ordering[i]
      end
    end
    return core, dead
  end

  ####################################
  # optimized get_core_and_dead()
  ####################################

  def does_it_reach_one_opt?(v, through_high_array, through_low_array, updated_hops_array)

    def update_reduced_vertices_opt(v, direction, through_high_array, through_low_array, updated_hops_array)
      if (direction == :high) and (updated_hops_array[@bdd[v].index] < @bdd[@bdd[v].high].index-1)
        updated_hops_array[@bdd[v].index] = @bdd[@bdd[v].high].index-1
        ((@bdd[v].index+1)..(@bdd[@bdd[v].high].index-1)).each do |i|
          through_high_array[i] = true
          through_low_array[i] = true
        end
      elsif (direction == :low) and (updated_hops_array[@bdd[v].index] < @bdd[@bdd[v].low].index-1)
        updated_hops_array[@bdd[v].index] = @bdd[@bdd[v].low].index-1
        ((@bdd[v].index+1)..@bdd[@bdd[v].low].index-1).each do |i|
          through_high_array[i] = true
          through_low_array[i] = true
        end
      end
    end


    puts "does_it_reach_one_opt?(#{v})"

    if (!@bdd[v].mark)
      through_high = false
      through_low = false
      @bdd[v].mark = true
      if @bdd[v].high == 1
        puts "por h1"
        through_high_array[@bdd[v].index] = true
        through_high = true
        update_reduced_vertices_opt(v, :high, through_high_array, through_low_array, updated_hops_array)
      elsif @bdd[v].high != 0
        puts "por h2"
        through_high = does_it_reach_one_opt?(@bdd[v].high, through_high_array, through_low_array, updated_hops_array)
        puts "comming back to #{v} from h2"
        if through_high
          through_high_array[@bdd[v].index] = true
          update_reduced_vertices_opt(v, :high, through_high_array, through_low_array, updated_hops_array)
        end
      end
      if @bdd[v].low == 1
        puts "por l1"
        through_low_array[@bdd[v].index] = true
        through_low = true
        update_reduced_vertices_opt(v, :low, through_high_array, through_low_array, updated_hops_array)
      elsif @bdd[v].low != 0
        puts "por l2"
        through_low = does_it_reach_one_opt?(@bdd[v].low, through_high_array, through_low_array, updated_hops_array)
        puts "comming back to #{v} from l2"
        if through_low
          through_low_array[@bdd[v].index] = true
          update_reduced_vertices_opt(v, :low, through_high_array, through_low_array, updated_hops_array)
        end
      end
    else
      through_high = through_high_array[@bdd[v].index]
      through_low = through_low_array[@bdd[v].index]
    end
    p through_high_array
    p through_low_array
    return (through_high or through_low)

  end

  def get_core_and_dead_opt()
    through_high_array = Array.new(var_ordering.length, false)
    through_low_array = Array.new(var_ordering.length, false)
    updated_hops_array = Array.new(var_ordering.length)
    i = 0
    while i<var_ordering.length
      updated_hops_array[i] = i
      i +=1
    end
    core = Array.new
    dead = Array.new
    does_it_reach_one_opt?(bdd_length-1, through_high_array, through_low_array, updated_hops_array)
    (0..var_ordering.length-1).each do |i|
      if through_high_array[i] and !through_low_array[i]
        core << var_ordering[i]
      elsif !through_high_array[i] and through_low_array[i]
        dead << var_ordering[i]
      end
    end
    p updated_hops_array
    return core, dead
  end
end #BDD

