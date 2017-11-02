#!/usr/bin/env ruby
require 'erb'
require 'benchmark'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//netlist2cnf.rb"
require "#{File.dirname(__FILE__)}//fujita88.rb"
require "#{File.dirname(__FILE__)}//malik88.rb"
require "#{File.dirname(__FILE__)}//force.rb"
require "#{File.dirname(__FILE__)}//parse_def.rb"
require "#{File.dirname(__FILE__)}//interleaving.rb"
require "#{File.dirname(__FILE__)}//mince.rb"
require "#{File.dirname(__FILE__)}//calc_span.rb"
require "#{File.dirname(__FILE__)}//test_bdd_lib.rb"
require "#{File.dirname(__FILE__)}//show_info_lib.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require "#{File.dirname(__FILE__)}//sendmail.rb"
require "#{File.dirname(__FILE__)}//parse_options.rb"


function = FUNCTION.new("/Users/rbean/temp/REAL-FM-4.xml",false)
change = (function.inputs.size  * 0.125).ceil.to_i * 2
preorder = function.getDFSOrderInputs(true)
print "#{change} over #{function.inputs.size}\n"
srand(100)

(1..1).to_a.each do |i|
  print "Iteration #{i}\n"
  values = preorder.sample(change)
  new_order = preorder.clone
  (0..(change/2-1)).to_a.each do |j|
    index_var1 = preorder.find_index(values[j*2])
    index_var2 = preorder.find_index(values[j*2+1])
    new_order[index_var2] = values[j*2]
    new_order[index_var1] = values[j*2+1]

    #print "index_1 #{index_var1} \t #{index_var2}\n"
  end
  print "change #{values}\n"
  print "prev_order #{preorder}\n"
  print "new_order #{new_order}\n"


  function.calcDFSInput()
  heur = Heur.new("random#{i}", new_order)
  heur.print_name = "random#{i}"

  heuristics  = Array.new()
  heuristics << heur
  span = calcSpanAndComplexity(function, heuristics)
  calc_desc = true
  _wait_time = 6000
  cpu_time = Hash.new()
  cpu_time[heur.order] = 10
  grown_file = "~/temp/kk.txt"
  write_dot = false

  circuit = function
  span = "100"
  erbFile  = File.join(File.dirname(__FILE__),"test_bdd_heuristic.erb")
  $stderr.print "erbfile: #{erbFile}\n"
  render = ERB.new(File.new(erbFile).read())
  output = render.result(binding)


  fd = open(File.join(File.dirname(__FILE__),"test_ruby.cc"), "w")
  fd.write(output)
  fd.close()

end



