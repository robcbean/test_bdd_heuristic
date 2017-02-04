#!/usr/bin/env ruby

orders = Hash["" => "circuit.inputs", "fujita88" => "order_fujita", "malik88_fanin" => "order_malik_fanin", "malik88_level" => "order_malik_level", "force" => "order_force"]

reorders = ["CUDD_REORDER_WINDOW2", "CUDD_REORDER_WINDOW3", "CUDD_REORDER_WINDOW4", "CUDD_REORDER_SIFT", "CUDD_REORDER_SYMM_SIFT", "CUDD_REORDER_ANNEALING", "CUDD_REORDER_GENETIC"]


orders.each do |order, inputlist|
  print "\"#{order}\",#{inputlist}\n"
  reorders.each do |reorder|
    print "\"#{order}\",#{inputlist},#{reorder}\n"
  end
end



