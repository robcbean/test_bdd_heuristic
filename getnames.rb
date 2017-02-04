#!/usr/bin/env ruby

require 'nokogiri'



Dir.foreach(ARGV[0]) do |file_name|
    file_name = File.join(ARGV[0],file_name)
    if File.file?(file_name)
        xmlDoc = Nokogiri::XML(File.open(file_name))
        name = xmlDoc.xpath('//feature_model').attribute("name").to_s
        print "#{file_name}\t#{name}\n"
    end
end

