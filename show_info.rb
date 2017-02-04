#!/usr/bin/env ruby
require 'descriptive-statistics'
require "#{File.dirname(__FILE__)}//function.rb"
require "#{File.dirname(__FILE__)}//utils.rb"
require "#{File.dirname(__FILE__)}//show_info_lib.rb"


if ARGV.size > 0
  print "file\t#{headerInfo}\n"
  if File.file?(ARGV[0])
    print "#{ARGV[0]}\t#{getFunctionInfo(ARGV[0]).to_s}\n"
  else
    Dir.glob(File.join(ARGV[0], "/*.*")).each do |file|
      if File.file?(file)
        $stdout.print "#{file}\t#{getFunctionInfo(file).to_s}\n"
      end
    end
  end
end




