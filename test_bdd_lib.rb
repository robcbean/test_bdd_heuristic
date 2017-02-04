#!/usr/bin/env ruby
require 'erb'
require 'os'
require 'benchmark'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//netlist2cnf.rb"
require "#{File.dirname(__FILE__)}//fujita88.rb"
require "#{File.dirname(__FILE__)}//malik88.rb"
require "#{File.dirname(__FILE__)}//force.rb"
require "#{File.dirname(__FILE__)}//parse_def.rb"
require "#{File.dirname(__FILE__)}//interleaving.rb"
require "#{File.dirname(__FILE__)}//calc_span.rb"
require "#{File.dirname(__FILE__)}//narodytska.rb"
require "#{File.dirname(__FILE__)}//mendonca.rb"
require "#{File.dirname(__FILE__)}//symmetry.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"


def selectBestOrderBySpan(_span)
  ret = ""
  best_span = Float::INFINITY

  _span.each do |heur,span|
    if span < best_span
      best_span = span
      ret = heur
    end
  end

  return ret

end


def getHeader(_minisat,_calc_desc)
  ret = "file\torder\treorder\talgo_time\tbdd_time\treorder_time"
  if _calc_desc
    ret  = ret + "\tand_time\treach_one_time\treach_one_time_total\tsum_nodes"
  end
  if printMinters
    ret = ret + "\tminterms"
  end
  ret = ret + "\tspan"
  if calcComplexity? or calcAllSpan? or calcNewSpan?
    if calcComplexity?
      ret = ret  + "\tcomplexity"
    else
      if calcAllSpan?
        ret = ret  + "\tall_span"
      else
        ret = ret + "\tnew_span"
      end
    end
  end
  ret =ret + "\t#{headerInfo}"
  if printSymmetric? and _minisat
    ret = ret + "\tsymmetric_variables"
  end
  ret = ret + "\tmaxnode\ttotal"

  ret = ret + "\n"

  return ret
end

# TODO : ROB 13/04/16 add a random heuristic, it's necessary
def generate_random_heuristics(_function, _cpu_time, _heuristics, _number_of_orders, _number_of_variables)

  (0.._number_of_orders-1).to_a.each do |random_order|
    tmp_order = Permutation.new(_number_of_variables).random.value
    order = Array.new()
    tmp_order.each do |variable|
      order << _function.inputs[variable]
    end
    heuristic = Heur.new("random#{random_order}", order)
    heuristic.print_name = "random"
    _heuristics << heuristic
    _cpu_time[heuristic.name] = 0.0
  end

end


def process_file(_input_file, _output_file, _heuristics_file, _wait_time, _random_orders, _grown_file,_minisat,_best_span,_calc_desc,_write_dot,_mcl)


  function = FUNCTION.new(_input_file,_minisat)
  heuristics = Array.new()


  basename = File.basename(_output_file)
  extname = File.extname(_output_file)
  basename.gsub!(/#{extname}/, "")
  cc_file = _output_file
  cpu_time = Hash.new()

  parse_definition_orders = get_parse_definitions_orders(_heuristics_file)
  calc_desc = _calc_desc
  write_dot = _write_dot

  cpu_time["netlist"] = 0.0
  if parse_definition_orders.include?("fujita88")
    $stderr.print "generating #{_input_file} fujita88 order ...\n"
    cpu_time["fujita88"] = Benchmark.measure { $order_fujita = fujita88(function) }.utime
    order_fujita=$order_fujita
  end
  if parse_definition_orders.include?("malik88_fanin")
    $stderr.print "generating #{_input_file} malik88 fanin order ...\n"
    cpu_time["malik88_fanin"] = Benchmark.measure { $order_malik_fanin = malik88fanin(function) }.utime
    order_malik_fanin = $order_malik_fanin
  end
  if parse_definition_orders.include?("malik88_level")
    $stderr.print "generating #{_input_file} malik88 level order ...\n"
    cpu_time["malik88_level"]= Benchmark.measure { $order_malik_level = malik88level(function) }.utime
    order_malik_level = $order_malik_level
  end
  if parse_definition_orders.include?("fuji93")
    $stderr.print "generating #{_input_file} fuji93 level order ...\n"
    cpu_time["fuji93"] = Benchmark.measure { $order_fuji_inter = getFuji1993(function) }.utime
    order_fuji_inter = $order_fuji_inter
  end


  if function.type == "SPLOT"
    if parse_definition_orders.include?("narodyska")

     $stderr.print "generating #{_input_file} narodyska order ...\n"
     cpu_time["narodyska"] = Benchmark.measure { $order_narodyska = getNarodystka(function) }.utime
     $stderr.print "generating #{_input_file} mendonca order ...\n"
     order_narodyska = $order_narodyska
     if _mcl != ""
        values = _mcl.split("-")
        range = Range.new(values[0].to_f,values[2].to_f)
        range.step(values[1].to_f) do |i|
          naro_name = "narodyska-#{i}"
          cpu_time[naro_name] = Benchmark.measure { $order_narodyska = getNarodystka(function,i) }.utime
          heuristic = Heur.new(naro_name, $order_narodyska)
          heuristic.print_name = naro_name
          heuristics << heuristic
        end
      end
    end

    if parse_definition_orders.include?("mendonca")
      res_mendoca= getMendonca(_input_file, function)
      cpu_time["mendonca"] = res_mendoca.heuristic_time
      $order_mendonca = res_mendoca.order
      order_mendonca = $order_mendonca
    end

  end


  $stderr.print("expanding function  #{function.name}...\n")
  function.expandFunction()
  if parse_definition_orders.include?("force")
    $stderr.print "generating #{_input_file} force order...\n"
    cpu_time["force"] = Benchmark.measure { $order_force = getFORCEOrder(function) }.utime
    order_force = $order_force
  end

  #<< ROB : 20/11/2016 add symmetry order
  if parse_definition_orders.include?("symmetry")
    $stderr.print "generating symmetry order ...\n"
    cpu_time["symmetry"] = Benchmark.measure { $order_symmetry = order_symmetry(function)}.utime
    order_symmetry = $order_symmetry
  end
  #<< ROB : 20/11/2016 add symmetry order

  cpu_time.keys.each do |key|
    value = cpu_time[key]
    cpu_time[key] = "%0.10f" % value
  end


  circuit = function
  heuristics.concat(parse_definition(function, binding, _heuristics_file))

  generate_random_heuristics(circuit, cpu_time, heuristics, _random_orders, function.inputs.size)
  span = calcSpanAndComplexity(function, heuristics)

  function.calcDFSInput()
  grown_file = _grown_file

  #<< ROB : 20/12/2016 If select best span only select the best heuristic
  if _best_span
    best_order = selectBestOrderBySpan(span)
    heuristics.select!{|heur| heur.name == best_order}
  end
  #<< ROB : 20/12/2016 If select best span only select the best heuristic

  heuristics.each do |heur|

    if not heur.order.nil?

      if printOrder and not circuit.extra_info.nil?
        order_names = Array.new()
        heur.order.each do |variable|
          order_names << circuit.extra_info.variables[variable]
        end
        $stderr.print("HeuristicOrder #{heur.name}: #{order_names.to_s}\n")
      end

      #<< ROB : 15/12/2016 if group and reorder group order
      if circuit.type == "SPLOT" and heur.group and ["CUDD_REORDER_SYMM_SIFT","CUDD_REORDER_GROUP_SIFT"].include?(heur.reorder) and printOrder
        heur.order = generatePermutationAccordingGroups(circuit.inputs, heur.order, circuit.extra_info.symmetric_groups)
        if printOrder
          order_names = Array.new()
          heur.order.each do |variable|
            order_names << circuit.extra_info.variables[variable]
          end
          $stderr.print("HeuristicOrder interleving #{heur.name} #{order_names.to_s}\n")
        end
      end
      #<< ROB : 15/12/2016 if group and reorder group order

      $stderr.print "generating c++ file #{cc_file} ...\n"
      erbFile  = File.join(File.dirname(__FILE__),"test_bdd_heuristic.erb")
      $stderr.print "erbfile: #{erbFile}\n"
      render = ERB.new(File.new(erbFile).read())
      output = render.result(binding)

      fd = open(File.join(File.dirname(__FILE__),cc_file), "w")
      fd.write(output)
      fd.close()


      $stderr.print "compiling #{cc_file} ...\n"
      include_dir = "-I ../../bdd/src/cudd-3.0.0/mtr/ -I ../../bdd/src/cudd-3.0.0/cudd/ -I ../../bdd/src/cudd-3.0.0/epd/  -I ../../bdd/src/cudd-3.0.0/st/ -I ../../bdd/src/cudd-3.0.0/util/ -I ../../bdd/src/cudd-3.0.0/  -I /usr/local/include"
      if OS.linux? or OS.mac?
	name = `hostname`
        if name.strip == "ram.issi.uned.es"
            compiler = "g++ -D __UNED__ "
        else
          compiler = "g++ "
        end

        if OS.linux?
          compiler = compiler + " -std=gnu++11 "
        end

        cmd = "#{compiler} #{include_dir} output.cc operations.cc -L /usr/local/lib #{getOptimization} #{getDebug} #{cc_file}  -lcudd -o #{basename}"

        `#{cmd}`
        $stderr.print "executing #{basename} ...\n"
        output = `./#{basename}`
        print "#{output}"
      else
	#<< ROB : 08/01/2017 Replace include path
	include_dir.gsub!("../../bdd/src/cudd-3.0.0/","/cygdrive/c/Users/Roberto/Dropbox/Uned/Doctorado/bdd/src/cudd-3.0.0/")
	#>> ROB : 08/01/2017 Replace include path
        cmd = "c:\\cygwin64\\bin\\bash.exe --login -c \"g++  #{include_dir}   #{srcPathCygWin}/#{cc_file}   #{srcPathCygWin}/output.cc #{srcPathCygWin}/operations.cc  -std=gnu++11 -L /usr/local/lib  -lcudd -o  #{srcPathCygWin}/#{basename}\" "
        $stderr.print "comando:#{cmd}\n"
        `#{cmd}`
        $stderr.print "executing #{basename} ...\n"
        cmd = "c:\\cygwin64\\bin\\bash.exe --login -c \"  #{srcPathCygWin}/#{basename}.exe \""
        output = `#{cmd}`

        print "#{output}"
      end
      $stdout.flush
      $stderr.flush		
    end
  end
end















