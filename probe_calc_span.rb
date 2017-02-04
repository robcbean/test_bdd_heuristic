#!/usr/bin/env ruby
#!/usr/bin/env ruby
require 'erb'
require 'os'
require 'benchmark'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//new_span.rb"





if File.exists?(ARGV[0])

	function = FUNCTION.new(ARGV[0])
	function.loadFromFile(ARGV[0])
	function.expandFunction()
	function.calcDFSInput()
	function.calcDFSOutput()

	new_span = calcNEWSPAN(function,function.inputs,function.dfs_inputs)

	hypergraph =generateHyperGraph(function)
	norm_span = hypergraph.calculateSPAN(function,function.inputs,function.dfs_inputs)
	
	print "Total clauses:#{function.clauses.size}\n"
	print "New span #{new_span}\tNorm span:#{norm_span}\n"


end









