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
require "#{File.dirname(__FILE__)}//calc_span.rb"
require "#{File.dirname(__FILE__)}//test_bdd_lib.rb"
require "#{File.dirname(__FILE__)}//show_info_lib.rb"
require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require "#{File.dirname(__FILE__)}//sendmail.rb"
require "#{File.dirname(__FILE__)}//parse_options.rb"



options = parse_options(ARGV)
heuristics_file = options[:heuristics]
wait_time = options[:wait_time]
random = options[:random]
number_of_attempts = options[:attemps]
file_input  = options[:file]
minisat = options[:minisat]
best_span = options[:best_span]
calc_desc = options[:calc_desc]
write_dot = options[:write_dot]
mcl = options[:mcl]

if file_input.nil?
  $stderr.print("You must put the input file\n")
  exit(0)
end


grown_file = grownFile
if File.exist?(grown_file)
  File.delete(grown_file)
end

fd = File.open(grown_file, "w")
fd.write("file\torder\tid\tclause\tnodes\n")
fd.close()

test_file = "test_ruby.cc"

print "#{getHeader(minisat,calc_desc)}"

(0..number_of_attempts).to_a.each do |attempt|
  if File.file?(file_input)
    process_file(file_input, test_file, heuristics_file, wait_time, random, grown_file,minisat,best_span,calc_desc,write_dot,mcl)
  else
    Dir.glob(File.join(file_input, "/*.*")).each do |file|
      $stderr.print("Process file #{file}\n")
      if File.file?(file)
        process_file(file, test_file, heuristics_file, wait_time, random, grown_file,minisat,best_span,calc_desc,write_dot,mcl)
      end
    end
  end
end


if sendMail?
  name = `hostname`
  sendFinishEmail("#{name}: #{__FILE__} #{ARGV.join(' ')}")
end














