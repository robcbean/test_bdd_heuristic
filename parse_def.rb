class Heur
  attr_accessor :name, :order, :reorder, :expanded, :print_name, :group

  def initialize(_name, _order, _reorder="", _expanded=false,_group=false)
    @name = _name
    @order = _order
    @reorder = _reorder
    @expanded = _expanded
    @print_name = _name
    @group = _group
  end
end


def get_parse_definitions_orders(_filename)

  ret = Array.new()
  if File.exist?(_filename)
    File.open(_filename).readlines.each do |line|
      if not line.include?("#")
        record = line.split(",")
        ret << (record[0].gsub(/\"/, '')).gsub("\n","")
      end
    end
  end
  return ret

end


def transform_heuristic_to_order(_heuristic)
  ret = ""
  if( _heuristic == '"netlist"')
    ret = "circuit.getDFSOrderInputs"
  elsif (_heuristic == '"fujita88"')
    ret  = "order_fujita"
  elsif (_heuristic == '"malik88_fanin"')
    ret = "order_malik_fanin"
  elsif (_heuristic == '"malik88_level"')
    ret = "order_malik_level"
  elsif (_heuristic == '"force"')
    ret = "order_force"
  elsif (_heuristic == '"fuji93"')
    ret = "order_fuji_inter"
  elsif (_heuristic == '"narodyska"')
    ret = "order_narodyska"
  elsif (_heuristic == '"mendonca"')
    ret = "order_mendonca"
  elsif (_heuristic == '"symmetry"')
    ret = "order_symmetry"
  end
  return ret
end


def parse_definition(_function, _binding, _filename)
  ret = Array.new()

  expanded = false


  if File.exists?(_filename)
    File.open(_filename).readlines.each do |line|
      if not line.include?("#")
        group = false
        line = line.gsub(/\s+/,"")
        record = line.split(",")
        name = record[0]
        #order_name = record[1].gsub("\n", "")
        order_name = transform_heuristic_to_order(name.gsub("\n",""))
        order = eval("#{order_name}", _binding)
        if record.size > 1
          reorder = record[1].gsub("\n", "")
        else
          reorder = ""
        end

        # if record.size > 3
        #   str_expanded = record[3].gsub("\n", "")
        #   if str_expanded == "Y"
        #     expanded = true
        #   else
        #     expanded = false
        #   end
        # end

        if record.size > 2
          str_group = record[2].gsub("\n","")
          if str_group == "Y"
            group = true
          end
        end

        if not (_function.type != "SPLOT" and (order == "narodyska" or order == "symmetry") )
          heur = eval("Heur.new(#{name},order,\"#{reorder}\")")
          heur.expanded = expanded
          heur.group = group
          ret.push(heur)
        end

      end
    end
  end
  return ret
end
