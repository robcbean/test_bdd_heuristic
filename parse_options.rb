require 'optparse'



def parse_options(args)


  ret = {:file => nil, :heuristics => "heuristics.txt", :wait_time => 600, :random => 0, :attemps => 0, :minisat => false, :best_span => false, :calc_desc => false, :write_dot => false, :mcl => "", :random_factor => 0.0}
  parser = OptionParser.new do |opts|

    opts.banner  = "Usage: test_bdd_heuristics.rb [options]"

    opts.on("-f","--file file","File or directory") do |file|
      ret[:file] = file
    end

    opts.on("-e","--heuristics file","Heuristics to analyze") do |heuristics|
      ret[:heuristics] = heuristics
    end

    opts.on("-t","--wait_time wait_time","Wait time") do |wait_time|
      ret[:wait_time] = wait_time.to_i
    end

    opts.on("-r","--random random ","Random") do |random_opt|
      ret[:random] = random_opt.to_i
    end

    opts.on("-a","--attemps attemps","Attemps") do |attemps|
      ret[:attemps] = attemps.to_i
    end

    opts.on("-m","--minisat","Launch minisat++") do |minisat|
      ret[:minisat] = true
    end

    opts.on("-b","--best_span","Select best span") do |best_span|
      ret[:best_span] = best_span
    end

    opts.on("-d","--calc_des","Calculate descomposition") do |calc_desc|
      ret[:calc_desc]  = calc_desc
    end

    opts.on("-w","--write_dot ","Write dot file") do |write_dot|
      ret[:write_dot]  = write_dot
    end

    opts.on("-c","--mcl_range from-step-to ","Mcl range") do |mcl|
      ret[:mcl]  = mcl
    end


    opts.on("-o","--random_factor random_factor ","Random factor") do |random_factor|
      ret[:random_factor]  = random_factor
    end


    opts.on("-h","--help","Display Help") do
      puts opts
      exit(0)
    end

  end


  parser.parse(args)



  return ret

end