#!/usr/bin/env ruby
require 'erb'
require 'benchmark'
require 'descriptive-statistics'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//netlist2cnf.rb"
require "#{File.dirname(__FILE__)}//fujita88.rb"
require "#{File.dirname(__FILE__)}//malik88.rb"
require "#{File.dirname(__FILE__)}//force.rb"
require "#{File.dirname(__FILE__)}//parse_def.rb"
require "#{File.dirname(__FILE__)}//interleaving.rb"


class FunctionInfo
  attr_accessor :inputs, :functions, :clauses, :mean_clauses, :mean_functions, :mean_input, :mean_levels

  #Average over all functions function.inputs / @inputs similar to ECR
  def calcMeanFunctions(_function)
    calc = Array.new()
    #ret = 0.0
    _function.outputs.each do |output|
      clause = _function.clauses[output]
      if not clause.nil?
        if not clause.null_function
          calc << clause.inputs.size.to_f/@inputs * 100
          #ret = ret + clause.inputs.size.to_f/@inputs
          #print "#output_#{clause.id} #{clause.inputs.size.to_f/@inputs}\n"
        end
      end
    end
    #ret = ret / (@functions) * 100
    ret = DescriptiveStatistics::Stats.new(calc)
  end

  # Average over all not null clauses clauses #orig_inputs /#function.inputs 
  def calcMeanClauses(_function)
    calc = Array.new()
    _function.clauses.values.each do |clause|
      #clause = _function.clauses[clause_id]
      if not clause.null_function and clause.orig_clause != ""
        #ret = ret + clause.orig_inputs.size.to_f/@inputs
        calc << clause.inputs.size.to_f/@inputs*100
      end
    end
    #ret = ret / (@clauses) * 100
    ret = DescriptiveStatistics::Stats.new(calc)
    return ret
  end

  # Average over all inputs  #clauses include input/#clauses
  def calcMeanInput(_function)
    calc = Array.new()
    _function.dfs_inputs.each do |input|
      function_count = 0.0
      _function.clauses.keys.each do |output_id|
        clause = _function.clauses[output_id]
        if not clause.null_function and clause.orig_clause != ""
          if clause.inputs.include?(input)
            function_count = function_count +1
          end
        end
      end
      #ret = ret + function_count / @clauses
      calc << function_count / @clauses * 100
      #$stderr.print "#{input} : #{function_count/@clauses}\n"
    end
    ret = DescriptiveStatistics::Stats.new(calc)
    #ret = ret / @inputs * 100

    return ret

  end

  #Average of input levels calculate mean function
  def calcLevels(_function)
    calc = Array.new()
    levels = Hash.new()
    _function.dfs_inputs.each do |input|
      compute_level(_function, input, levels, method(:get_fanouts))
    end

    levels.keys.each do |input|
      if _function.dfs_inputs.include?(input)
        calc << levels[input]
      end
    end
    ret = DescriptiveStatistics::Stats.new(calc)

    return ret

  end

  #Average input levels check where

  def calcFunctionInfo(_function)

    @inputs = _function.getDFSOrderInputs.size.to_f
    @clauses = (_function.clauses.size - _function.clauses.values.select { |clause| clause.orig_clause == "" }.size).to_f
    @functions = (_function.outputs.size - _function.clauses.values.select { |clause| clause.null_function }.size).to_f
    @mean_clauses = self.calcMeanClauses(_function)
    @mean_functions = self.calcMeanFunctions(_function)
    @mean_input = self.calcMeanInput(_function)
    @mean_levels = self.calcLevels(_function)
  end

  def initialize(_inputs=0.0, _functions=0.0, _clauses=0.0, _mean_clauses=0.0, _mean_functions=0.0, _mean_inputs=0.0)
    if _inputs.kind_of?(FUNCTION)
      self.calcFunctionInfo(_inputs)
    else
      @inputs = _inputs
      @clauses = _clauses
      @functions = _functions
      @mean_clauses = _mean_clauses
      @mean_functions = _mean_functions
      @mean_input = _mean_inputs
    end
  end

  def showStats(_stats)
    ret = "#{_stats.mean.to_s}\t#{_stats.standard_deviation}\t#{_stats.median}"
  end

  def to_s
    if showStatistics
      stat_info = "\t#{showStats(@mean_clauses)}\t#{showStats(@mean_functions)}\t#\t#{showStats(@mean_input)}\t#{showStats(@mean_levels)}"
    else
      stat_info  = "\t#{showStats(@mean_functions)}"
    end
    ret = "#{@inputs}\t#{@clauses}\t#{@functions}#{stat_info}"
    return ret
  end

end


def getFunctionInfo(_filename)
  $stderr.print "lading #{_filename} ...\n"
  function = FUNCTION.new(_filename)
  function.loadFromFile(_filename)
  $stderr.print "expanding  #{_filename} ...\n"
  function.expandFunction()
  $stderr.print "calc DFS output  #{_filename} ...\n"
  function.calcDFSOutput()
  $stderr.print "calc DFS input  #{_filename} ...\n"
  function.calcDFSInput()
  return FunctionInfo.new(function)
end

def statInfo(_info)
  ret = "\tmean (#{_info})\tstandard deviation (#{_info})\tmedian (#{_info})"
end

def headerInfo()
  if showStatistics()
    stat_info = "#{statInfo("variables_in_clause")}#{statInfo("variables_in_functions")}#{statInfo("variable_in_clauses")}#{statInfo("variable_mean_level")}"
  else
    stat_info = "#{statInfo("variables_in_functions")}"
  end
  return "inputs\tclauses\tfunctions#{stat_info}"
end





