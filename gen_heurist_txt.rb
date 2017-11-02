#!/usr/bin/env ruby

orders = Hash["" => "circuit.inputs", "fujita" => "order_fujita", "malik_fanin" => "order_malik_fanin", "malik_level" => "order_malik_level", "FORCE" => "order_force", "MINCE" => "order_mince"]

reorders = ["CUDD_REORDER_WINDOW2", "CUDD_REORDER_WINDOW3", "CUDD_REORDER_WINDOW4", "CUDD_REORDER_SIFT", "CUDD_REORDER_SYMM_SIFT", "CUDD_REORDER_ANNEALING", "CUDD_REORDER_GENETIC"]


orders.each do |order, inputlist|
  print "\"#{order}\",#{inputlist}\n"
  reorders.each do |reorder|
    print "\"#{order}\",#{inputlist},#{reorder}\n"
  end
end



