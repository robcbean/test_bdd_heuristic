#!/usr/bin/env ruby


def transformFile(_filename, _output=$stdout)

  transform = Hash.new()

  File.open(_filename).readlines().each { |line|

    if line =~ /OUTPUT/
      line.gsub!(/OUTPUT/, "")
      line.gsub!(/\(|\)/, "")
      line.gsub!(/\s+/, "")
      if not transform.keys.include?(line)
        transform[line] = transform.size()+1
      end
    end

    if line =~ /INPUT/
      line.gsub!(/INPUT/, "")
      line.gsub!(/\(|\)/, "")
      line.gsub!(/\s+/, "")
      if not transform.keys.include?(line)
        transform[line] = transform.size()+1
      end

    end

    if line =~ /=/
      output = line.split("=")[0]
      output.gsub!(/\s+/, "")
      if not transform.keys.include?(output)
        transform[output] = transform.size()+1
      end
    end

  }


  File.open(_filename).readlines().each { |line|
    transform.keys.sort_by { |x| x.length }.reverse.each do |key|
      line.gsub!(/#{key}/, transform[key].to_s)
    end
    _output.print "#{line}"
  }
end


if ARGV.size > 0
  if File.file?(ARGV[0])
    output = File.open(File.basename(ARGV[0]), "w")
    transformFile(ARGV[0], output)
  else
    Dir.glob(File.join(ARGV[0], "/*.bench")).each do |file|
      if File.file?(file)
        $stderr.print "Processing #{file}\n"
        output = File.open(File.basename(file), "w")
        transformFile(file, output)
      end
    end
    output.close()
  end
end