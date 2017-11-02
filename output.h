#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include "cuddObj.hh"
#include <sys/time.h>
#include <sys/resource.h>
#include <math.h>
#include <stdio.h>



#ifdef __UNED__
using namespace cudd;
#endif


#define MINTERMS_FILE "minterms.txt"
#define SYMMETRIC_FILE "symmetric.txt"


void print_output(int _nvars,std::string _file,std::string _type, Cudd& _mgr,std::vector<BDD>& _output, bool _procesed, BDD* _function, bool _get_total);
double get_user_time();
double get_diftime(double _ts, double _te);
void writeSize(std::string _file_name, std::string _function_file, std::string _order, std::vector<unsigned long>& _count_nodes, std::vector<unsigned long> _count_id);
double countMinterms(Cudd& _mgr,BDD& _node);
std::string totalSymmetric(Cudd& _mgr,BDD& _bdd, unsigned int _total_nodes);
