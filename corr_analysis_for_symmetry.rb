#require "#{File.dirname(__FILE__)}//bdd.rb"
require 'erb'
require 'permutation'
#require 'profile'

#require "benchmark"
#include Benchmark

#require 'bdd' # BudDD


class SymmetricGroup
  attr_accessor :variables, :type, :grouped_in_ordering
  # type in {mandatory, or, xor, excludes}
  def initialize(variables, type)
    @variables = variables
    @type = type
    @grouped_in_ordering = false
  end
end

class SymmetricGroups
  attr_accessor :groups
  attr_accessor :mandatory, :or, :xor, :excludes

  def initialize(groups)
    @groups = groups
    @mandatory = 0
    @or = 0
    @xor = 0
    @excludes = 0
    groups.each do |group|
      case group.type
        when :mandatory
          @mandatory += 1
        when :or
          @or += 1
        when :xor
          @xor += 1
        when :excludes
          @excludes +=1
      end
    end
  end

  def reset!
    @groups.each do |g|
      g.grouped_in_ordering = false
    end
  end
end

class PermutationStats
  attr_accessor :nodes, :mandatory, :or, :xor, :excludes, :all

  def initialize(nodes, symmetric_groups)
    @nodes = nodes
    @mandatory = 0
    @or = 0
    @xor = 0
    @excludes = 0
    symmetric_groups.groups.each do |group|
      if group.grouped_in_ordering
        case group.type
          when :mandatory
            @mandatory += 1
          when :or
            @or += 1
          when :xor
            @xor += 1
          when :excludes
            @excludes +=1
        end
      end
    end
    @all =100*((@mandatory + @or + @xor +@excludes).to_f/(symmetric_groups.mandatory + symmetric_groups.or + symmetric_groups.xor + symmetric_groups.excludes))
  end

end

def check_symmetric_groups(var_ordering, symmetric_groups)
  symmetric_groups.reset!
  var_ordering_str = var_ordering.join('')
  symmetric_groups.groups.each do |group|
    group_permutations = group.variables.permutation.to_a
    found = false
    i = 0
    while !found && i<group_permutations.length
      if (var_ordering_str[group_permutations[i].join('')])
        found = true
      end
      i += 1
    end
    group.grouped_in_ordering = found
  end
end

def get_symmetric_groups
  groups = [SymmetricGroup.new(['f4', 'f5', 'f6'], :xor), SymmetricGroup.new(['f7', 'f8'], :or), SymmetricGroup.new(['f6', 'f7'], :excludes)]
  return SymmetricGroups.new(groups)
end

def generate_n_permutations(number_of_variables, number_of_permutations, non_repeated = true)
  puts "Computing permutations..."
  perm = Permutation.new(number_of_variables)
  permutations = Array.new
  i = 0
  while i< number_of_permutations
    randomly_generated = perm.random.value
    if non_repeated
      if !permutations.include?(randomly_generated)
        permutations << randomly_generated
        i += 1
        if i%100 == 0
          puts "#{i} permutations generated"
        end
      end
    else
      permutations << perm.random.value
      i += 1
      if i%1000 == 0
        puts "#{i} permutations generated"
      end
    end
  end
  permutations
end

def get_stat_data(input_file, number_of_permutations, non_repeated=true)
  stats = Array.new
  computed_formula = parse_splot(input_file)

  symmetric_groups = SymmetricGroups.new(computed_formula.symmetric_groups)
  variables = computed_formula.variables
  variables_length = variables.length
  formula = computed_formula.formula
  formula.gsub!(/\band\b/, '&')
  formula.gsub!(/\bor\b/, '|')
  formula.gsub!(/\bnot\s+/, '!')

  permutations_generator = Permutation.new(symmetric_groups.groups.length)
  i = 0
  number_of_permutations100 = 25000
  permutations100 = Array.new
  while i< number_of_permutations100
    permutation_array = Array.new
    groups_perm = permutations_generator.random.value
    groups_perm.each do |group_index|
      group = symmetric_groups.groups[group_index]
      group_perm = Permutation.new(group.variables.length).random.value
      group_perm.each do |var_index_in_perm|
        var = group.variables[var_index_in_perm]
        var_index_in_variables = variables.index(var)
        permutation_array << var_index_in_variables
      end
    end
    variables_not_included_in_permutation = Array.new
    (0..(variables.length-1)).each do |j|
      if !permutation_array.include?(j)
        variables_not_included_in_permutation << j
      end
    end
    permutations100 << (permutation_array.uniq) + variables_not_included_in_permutation
    i += 1
  end

  if number_of_permutations.nil?
    permutations = (0..variables.length).to_a.permutation.to_a
  else
    permutations = generate_n_permutations(variables.length, number_of_permutations-permutations100.length, non_repeated)
    permutations += permutations100
  end
  permutations_length = permutations.length

  File.open("permutations.txt", 'w+') do |file|
    permutations.each do |perm|
      perm.each { |v| file.write("#{v}\n") }
    end
  end

  puts "#{permutations_length} permutations ..."

  File.open("buddy.cxx", "w+") { |f|
    renderer = ERB.new(File.new('buddy_template.cxx').read)
    f.write(renderer.result(binding))
  }
  `g++ buddy.cxx -o buddy -lbdd`

  `./buddy`

  File.open("symmetric_output.txt", "w+") do |file_symmetric|
    File.open("buddy_output.txt", "r") do |file_buddy|

      permutations.to_a.each do |perm|
        number_of_nodes = file_buddy.readline.strip
        variables_in_perm = Array.new
        perm.each { |p_i| variables_in_perm << variables[p_i] }
        check_symmetric_groups(variables_in_perm, symmetric_groups)
        stats << PermutationStats.new(number_of_nodes, symmetric_groups)
      end
    end
  end
  File.open("output_data.txt", 'w+') do |file|
    file.write("nodes total_percentage mandatory or xor excludes\n")
    stats.each { |stat| file.write("#{stat.nodes} #{stat.all} #{stat.mandatory} #{stat.or} #{stat.xor} #{stat.excludes}\n") }
  end

  File.open("#{input_file}_buddy_output.txt", 'w+') do |file|
    code_to_copy = ''
    File.open("#{File.dirname(__FILE__)}//output_data.txt", 'r') do |file_to_copy|
      code_to_copy = file_to_copy.read
    end
    file.write(code_to_copy)
  end

  puts "BuDDy has finished..."

  puts "let's call R..."

  puts `Rscript r_template.R > r_output.txt`

  puts "R has finished..."

  File.open("#{input_file}_r_output.txt", 'w+') do |file|
    code_to_copy = ''
    File.open("#{File.dirname(__FILE__)}//r_output.txt", 'r') do |file_to_copy|
      code_to_copy = file_to_copy.read
    end
    file.write(code_to_copy)
  end

  puts "cp histogram.pdf #{input_file}.pdf"
  `cp histogram.pdf #{input_file}.pdf`

  feature_model = ''
  File.open(input_file, 'r') do |file|
    splot_code = file.read
    splot_code =~ /feature_model name="(.+)"/
    feature_model = $1
  end
  min_nodes = nil
  max_nodes = nil
  mean = nil
  sd = nil
  mean0 = nil
  sd0 = nil
  min_nodes0 = nil
  max_nodes0 = nil
  mean100 = nil
  sd100 = nil
  min_nodes100 = nil
  max_nodes100 = nil

  File.open('r_output.txt', 'r') do |file|
    r_code = file.read
    # descriptive information
    r_code =~ /nodes(.+)$/
    nodes = $1.split
    min_nodes = nodes[7]
    max_nodes = nodes[8]
    mean = nodes[2]
    sd = nodes[3]
    r_code =~ /only[.]non[.]grouped.+?nodes(.+)$/m
    nodes = $1.split
    mean0 = nodes[2]
    sd0 = nodes[3]
    min_nodes0 = nodes[7]
    max_nodes0 = nodes[8]
    r_code =~ /only[.]all[.]grouped.+?nodes(.+)$/m
    nodes = $1.split
    mean100 = nodes[2]
    sd100 = nodes[3]
    min_nodes100 = nodes[7]
    max_nodes100 = nodes[8]
  end

  puts "#{feature_model} & #{variables.length} & #{mean} & #{sd} & [#{min_nodes.to_i}, #{max_nodes.to_i}] & #{mean0} & #{sd0} & [#{min_nodes0.to_i}, #{max_nodes0.to_i}] & #{mean100} & #{sd100} & [#{min_nodes100.to_i}, #{max_nodes100.to_i}] \\\\ \\hline\n"

  "#{feature_model} & #{variables.length} & #{mean} & #{sd} & [#{min_nodes.to_i}, #{max_nodes.to_i}] & #{mean0} & #{sd0} & [#{min_nodes0.to_i}, #{max_nodes0.to_i}] & #{mean100} & #{sd100} & [#{min_nodes100.to_i}, #{max_nodes100.to_i}] \\\\ \\hline\n"

end

def get_stat_data_for_parking(number_of_permutations)
  stats = Array.new
  input_file = "parking"

  formula = "(Dev) and (OS) and (Cap) and (Val) and (WiFi)"

  formula += " and (not Dev or P900 or Sym or iP)"
  formula += " and (not P900 or Dev) and (not Sym or Dev) and (not iP or Dev)"
  formula += " and (not P900 or not Sym) and (not P900 or not iP) and (not Sym or not iP)"

  formula += " and (not OS or Sy or Sy)"
  formula += " and (not Sy or OS) and (not Win or OS)"
  formula += " and (not Sy or not Win)"

  formula += " and (not Cap or r200 or r600 or r1024)"
  formula += " and (not r200 or Cap) and (not r600 or Cap) and (not r1024 or Cap)"

  formula += " and (not Val or SS or Loc)"
  formula += " and (not SS or Val) and (not Loc or Val)"
  formula += " and (not SS or not Loc)"

  formula += " and (not WLAN or WiFi) and (not GPRS or WiFi)"

  formula += " and (not P900 or Sy) and (not (Sym or iP) or Win)"
  formula += " and (not P900 or not r1024)"
  #formula += " and (not Sym or not r1024)"
  formula += " and (not SS or (WLAN or GPRS))"

  s1 = SymmetricGroup.new(["P900", "Sym", "iP"], :xor)
  s2 = SymmetricGroup.new(["Sy", "Win"], :xor)
  s3 = SymmetricGroup.new(["r200", "r600", "r1024"], :or)
  s4 = SymmetricGroup.new(["SS", "Loc"], :xor)
  s5 = SymmetricGroup.new(["P900", "r1024"], :excludes)
  #s6 = SymmetricGroup.new(["Sym", "r1024"], :excludes)

  symmetric_groups = SymmetricGroups.new([s1, s2, s3, s4, s5])

  variables = ["Dev", "OS", "Cap", "Val", "WiFi", "P900", "Sym", "iP", "Sy", "Win", "r200", "r600", "r1024", "SS", "Loc", "WLAN", "GPRS"]
  variables_length = variables.length
  formula.gsub!(/\band\b/, '&')
  formula.gsub!(/\bor\b/, '|')
  formula.gsub!(/\bnot\s+/, '!')

  permutations_generator = Permutation.new(symmetric_groups.groups.length)
  i = 0
  number_of_permutations100 = 5000
  permutations100 = Array.new
  while i< number_of_permutations100
    permutation_array = Array.new
    groups_perm = permutations_generator.random.value
    groups_perm.each do |group_index|
      group = symmetric_groups.groups[group_index]
      group_perm = Permutation.new(group.variables.length).random.value
      group_perm.each do |var_index_in_perm|
        var = group.variables[var_index_in_perm]
        var_index_in_variables = variables.index(var)
        permutation_array << var_index_in_variables
      end
    end
    variables_not_included_in_permutation = Array.new
    (0..(variables.length-1)).each do |j|
      if !permutation_array.include?(j)
        variables_not_included_in_permutation << j
      end
    end
    permutations100 << (permutation_array.uniq) + variables_not_included_in_permutation
    i += 1
  end

  permutations = generate_n_permutations(variables.length, number_of_permutations-permutations100.length, false)
  permutations += permutations100
  permutations_length = permutations.length

  File.open("permutations.txt", 'w+') do |file|
    permutations.each do |perm|
      perm.each { |v| file.write("#{v}\n") }
    end
  end

  puts "#{permutations_length} permutations ..."

  File.open("buddy.cxx", "w+") { |f|
    renderer = ERB.new(File.new('buddy_template.cxx').read)
    f.write(renderer.result(binding))
  }
  `g++ buddy.cxx -o buddy -lbdd`

  `./buddy`

  File.open("symmetric_output.txt", "w+") do |file_symmetric|
    File.open("buddy_output.txt", "r") do |file_buddy|

      permutations.to_a.each do |perm|
        number_of_nodes = file_buddy.readline.strip
        variables_in_perm = Array.new
        perm.each { |p_i| variables_in_perm << variables[p_i] }
        check_symmetric_groups(variables_in_perm, symmetric_groups)
        stats << PermutationStats.new(number_of_nodes, symmetric_groups)
      end
    end
  end
  File.open("output_data.txt", 'w+') do |file|
    file.write("nodes total_percentage mandatory or xor excludes\n")
    stats.each { |stat| file.write("#{stat.nodes} #{stat.all} #{stat.mandatory} #{stat.or} #{stat.xor} #{stat.excludes}\n") }
  end

  File.open("#{input_file}_buddy_output.txt", 'w+') do |file|
    code_to_copy = ''
    File.open("#{File.dirname(__FILE__)}//output_data.txt", 'r') do |file_to_copy|
      code_to_copy = file_to_copy.read
    end
    file.write(code_to_copy)
  end

  puts "BuDDy has finished..."

  puts "let's call R..."

  puts `Rscript r_template.R > r_output.txt`

  puts "R has finished..."

end

#get_stat_data_for_parking(25000)

=begin
unless ARGV[0]
  puts "<<ERROR>> corr_analysis_for_symmetry splot_files_dir number_of_permutations\n"
  exit
end

SplotFilesDir = ARGV[0]
splot_file = Array.new

if ARGV[1]
  number_of_permutations = ARGV[1].to_i
else
  number_of_permutations = nil
end

stat_analysis_result = ''
dir_entries = Dir.entries(SplotFilesDir)
dir_entries.each do |file_name|
  if !File.directory?(file_name) && (File.extname(file_name) == '.xml')
    puts "#################################"
    puts "Processing #{file_name}"
    puts "#################################"
    stat_analysis_result <<get_stat_data("#{SplotFilesDir}//#{file_name}", number_of_permutations, false)
  end
end

  File.open("#{SplotFilesDir}//stat_result.tex", 'w+') do |file|
    file.write(stat_analysis_result)
  end

=end






