require "#{File.dirname(__FILE__)}//constants_and_options.rb"
require 'os'

class MendocaResults
  attr_accessor :order, :heuristic_time

  def initialize(_order = Array.new(), _heuristic_time = nil)
    self.order = _order
    self.heuristic_time = _heuristic_time
  end
end

def getMendonca(_file_name, _function)
  cmd = "java -cp "
  if OS.windows?
    cmd = "#{cmd} #{srcPathDOSOnlyOne}\\mendonca\\bin\\.;#{srcPathDOSOnlyOne}\\mendonca\\lib\\splar.jar;#{srcPathDOSOnlyOne}\\mendonca\\lib\\javabdd.jar"
  else
    cmd = "#{cmd} mendonca/lib/splar.jar:mendonca/lib/javabdd.jar:mendonca/bin/."
  end
  cmd = "#{cmd} mendonca #{_file_name}"
  res = `#{cmd}`.split(" ")

  ret = MendocaResults.new()

  ret.heuristic_time = res[2]
  $stderr.print("mendoca size #{_file_name}\t#{res[0]} and minterms #{res[1]}\n")
  (3..res.length-1).each do |i|
    ret.order << _function.extra_info.variables.find_index(res[i].to_sym)
  end

  return ret

end

def getClausesByPreorder(_function, _feature_model=nil)
  ret = Array.new()
  if _feature_model.nil?
    feature_model = _function.extra_info.feature_model
  else
    feature_model = _feature_model
  end

  ret << feature_model.id
  feature_model.children.each do |child|
    ret = ret.concat(getClausesByPreorder(_function, child))
  end

  return ret

end
