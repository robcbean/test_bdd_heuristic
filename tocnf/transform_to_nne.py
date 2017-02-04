#!/usr/bin/env python
import sys
import copy
sys.path.append("/home/robbean/Uned/sw/PBL/PBL-master/include/")
sys.setrecursionlimit(10000)
import PyBool_public_interface as Bool


if __name__ == "__main__":

	if len(sys.argv) > 1:	
		clauses = Bool.parse_std(sys.argv[1])
		expr = Bool.nne(clauses["main_expr"])
		print Bool.print_expr(expr)
