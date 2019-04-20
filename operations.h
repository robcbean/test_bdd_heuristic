/*
 * operations.h
 *
 *  Created on: 20 dic. 2016
 *      Author: rbean
 */

#ifndef OPERATIONS_H_

#include <cuddObj.hh>
#include <cuddInt.h>
#include <string>
#include <list>
#include <map>
#include <iostream>
#include <limits.h>
#include <algorithm> 

#define OPERATIONS_H_


#define BUFFER_SIZE 100

struct feature_model_info
{
	std::list<unsigned int> core;
	std::list<unsigned int> dead;
	std::map<unsigned int,std::list<unsigned int>*> impact_set;
	std::map<unsigned int,std::list<unsigned int>*> exclusion_set;
	unsigned int* var_low;
	unsigned int* var_high;
};


void get_depen_conflic(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, unsigned int _num_vars,unsigned int* _var_low,unsigned int* _var_high);
feature_model_info* calc_dead_core_and_impact_exclusion(DdManager* _manager, DdNode** _nodes,unsigned int _nnodes, unsigned int _nvars);
feature_model_info* calc_dead_core_and_impact_exclusion_only_one(DdManager* _manager, DdNode* _node, unsigned int _nvars);


#endif /* OPERATIONS_H_ */
