/*
//<< ROB : 22/12/2016 Is zero if all are zero * operations.cc+
 *
 *  Created on: 20 dic. 2016
 *      Author: rbean
 */

#include "operations.h"




//<< ROB : 20/12/2016 Get a pointer string from a BDD CUDD Node
std::string get_pointer(DdManager* _mgr, DdNode* _f,std::string _direction)
{
	std::string ret;
	char buffer[BUFFER_SIZE];

	sprintf(buffer,"%p-%s",Cudd_Regular(_f),_direction.c_str());
	ret = std::string(buffer);

	return ret;
}
//>> ROB : 20/12/2016 Get a pointer string from a BDD CUDD Node



//<< ROB : 20/12/2016 Get the node index
unsigned int get_index(DdManager* _mgr, DdNode* _node){
	unsigned int ret = UINT_MAX;
	if(!cuddIsConstant(_node)){
		ret =  _mgr->perm[_node->index];
	}
	return ret;
}
//>> ROB : 20/12/2016 Get the node index


//<< ROB : 20/12/2016 Get the regular node index
unsigned int get_index_regular(DdManager* _mgr, DdNode* _node){
	unsigned int ret = UINT_MAX;
	if ( !cuddIsConstant(_node) ) {
		ret = get_index(_mgr,Cudd_Regular(_node));
	}
	return ret;
}
//<< ROB : 20/12/2016 Get the regular node index



//<< ROB : 20/12/2016 Get index from a vector array
unsigned int get_index(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes ) {

	unsigned int ret = UINT_MAX;
	unsigned int index;

	for(unsigned int i=0;i<_nnodes;i++)
	{
		index = get_index_regular(_manager,_nodes[i]);
		if( index < ret ){
			ret = index;
		}
	}

	return ret;
}
//<< ROB : 20/12/2016 Get index from a vector array

unsigned int get_minor_index(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes)
{
	unsigned int ret = -1;
	unsigned int index = UINT_MAX;

	for(unsigned int i=0; i<_nnodes;i++ )
	{
		if(_nodes[i] != NULL ){
			if(get_index(_manager,_nodes[i]) < index ){
				index = get_index(_manager,_nodes[i]);
				ret = index;
			}
		}
	}
	return ret;
}


unsigned int get_regular_minor_index(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes)
{
	unsigned int ret = -1;
	unsigned int index = UINT_MAX;

	for(unsigned int i=0; i<_nnodes;i++ )
	{
		if(_nodes[i] != NULL ){
			if(get_index_regular(_manager,_nodes[i]) < index ){
				index = get_index_regular(_manager,_nodes[i]);
				ret = index;
			}
		}
	}
	return ret;
}


//<< ROB :14/01/2017 Is one for only one node
bool is_one_node(DdManager* _manager, DdNode* _node )
{
    bool ret = DD_ONE(_manager) == _node;

    return ret;

}
//<< ROB :14/01/2017 Is one for only one node


//<< ROB :14/01/2017 Is one for only one node
bool is_zero_node(DdManager* _manager, DdNode* _node )
{
    bool ret = Cudd_Not(DD_ONE(_manager)) == _node;

    return ret;

}
//<< ROB :14/01/2017 Is one for only one node



//<< ROB : 22/12/2016 Is one if all are one
bool is_one(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, unsigned int _index ) {

	bool ret;
	DdNode *node,*regular_node;
	unsigned int constantNodes=0;
	unsigned int oneNodes=0;

	for(unsigned int i=0;i<_nnodes;i++)
	{
        node = _nodes[i];
        regular_node = Cudd_Regular(_nodes[i]);
        //if((node == DD_ONE(_manager) /*&& regular_node == DD_ONE(_manager))*/)
        if( node == DD_ONE(_manager)  /* regular_node == DD_ONE(_manager) */ )
        {
            oneNodes = oneNodes  + 1;
        }
	}
	ret = (oneNodes  == _nnodes);

    return ret;
}
//<< ROB : 22/12/2016 Is one if all are one

//<< ROB : 22/12/2016 Is zero if all are zero
bool is_zero(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, unsigned int _index ) {

	bool ret=false;
	DdNode *node,*regular_node;

	for(unsigned int i=0;i<_nnodes && !ret; i++)
	{
	    regular_node = Cudd_Regular(_nodes[i]);
	    node = _nodes[i];

	    if( /* regular_node == Cudd_Not(DD_ONE(_manager)) || */ node == Cudd_Not(DD_ONE(_manager)) )
	    {
	        ret = true;
	    }
	}

	return ret;
}
//>> ROB : 22/12/2016 Is zero if all are zero

//<< ROB : 22/12/2016 Convert pointers to string
std::string convert_pointers_to_string(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes, std::string _direction)
{
	std::string ret = "";
	char buffer[BUFFER_SIZE];

	for(unsigned int i=0;i< _nnodes;i++)
	{
		if(_nodes[i]!= NULL){
			sprintf(buffer,"%s",get_pointer(_manager,_nodes[i],_direction).c_str());
			if(ret.compare("")){
				ret = ret + "-";
			}
			ret = ret + buffer;
		}
	}
	return ret;
}
//<< ROB : 22/12/2016 Is zero if all are zero


//<< ROB : 23/12/2016 Update reduced nodes
void update_reduced_nodes(unsigned int _curindex, unsigned int _nextindex, unsigned int* _var_low, unsigned int* _var_high, unsigned int _size)
{
	if (_nextindex > _size ) {
		//return;
		_nextindex = _size;
		//_nextindex = _size;
	}
	if( _nextindex == 0 ) {
		return;
		//_nextindex = _size;
	}
	for( unsigned int i=_curindex+1; i < _nextindex; i++ ) {
		_var_high[i] = 1;
		_var_low[i] = 1;
	}
	return;

}
//>> ROB : 23/12/2016 Update reduced nodes

int get_depend_conflic_aux(
		std::map<std::string,bool>* _visited,
		DdManager* _manager,
		DdNode** _nodes,
		unsigned int _nnodes,
                           unsigned int _size,unsigned int* _var_low, unsigned int* _var_high, std::map<std::string,bool>* _reaches_one, std::string _direction
		)
{
	int ret = 0;
	DdNode** R = new DdNode*[_nnodes];
	DdNode** f = new DdNode*[_nnodes];
	DdNode** fn = new DdNode*[_nnodes];
	unsigned int top[_nnodes];

	//<< ROB : 22/12/2016 Calculate regular nodes and levels
	for(unsigned int i=0;i<_nnodes;i++){
		R[i] = Cudd_Regular(_nodes[i]);
		top[i] = get_index(_manager,R[i]);
	}
    
    //<< ROB : 23/12/2016 Set node has visited
    std::string strnode = convert_pointers_to_string(_manager,R,_nnodes,_direction);
    if(_visited->find(strnode) != _visited->end()){
        delete[] R;
        delete[] f;
        delete[] fn;
        return  (*_reaches_one)[strnode];
    }
    (*_visited)[strnode] = true;
    //<< ROB : 23/12/2016 Set node has visited


	//<< ROB : 23/12/2016 Get all descendends true and false
	unsigned int index = get_minor_index(_manager,R,_nnodes);
	for(unsigned int i=0;i<_nnodes;i++)
	{

		if(!cuddIsConstant(R[i])){
			if(top[i] <= index)
			{
				f[i] = cuddT(R[i]);
				fn[i] = cuddE(R[i]);
				if(Cudd_IsComplement(_nodes[i])){
					f[i] = Cudd_Not(f[i]);
					fn[i] = Cudd_Not(fn[i]);
				}
			}else{
				f[i] = _nodes[i];
				fn[i] = _nodes[i];
			}
		}else{
			f[i] = R[i];
			fn[i] = R[i];
		}
	}

	unsigned int indexT = get_regular_minor_index(_manager,f,_nnodes);
	unsigned int indexE = get_regular_minor_index(_manager,fn,_nnodes);

	//<< ROB : 23/12/2016 Does v reach the 1-terminal through high?
	if(is_one(_manager,f,_nnodes,index)){
        (*_reaches_one)[strnode] = true;
        if(index < _size){
            _var_high[index] = 1;
            if(indexT > index )
            {
                update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
            }
        }
	}else if (!is_zero(_manager,f,_nnodes,index)){
		//keep searching
		if(get_depend_conflic_aux(_visited,_manager,f,_nnodes,_size,_var_low, _var_high, _reaches_one,"1")){
			(*_reaches_one)[strnode] = true;
			_var_high[index] = 1;
			if(indexT > index){
				update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
			}
		}
	}
	//>> ROB : 23/12/2016 Does v reach the 1-terminal through high?


	//<< ROB : 23/12/2016 Does v reach the 1-terminal through low?
	if(is_one(_manager,fn,_nnodes,index)){
        (*_reaches_one)[strnode] = true;
		//the 1-terminal nodes is reached
        if(index < _size){
            _var_low[index] = 1;
            if(indexT > index )
            {
                update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
            }
        }
	}else if (!is_zero(_manager,fn,_nnodes,index)){
		//keep searching
		if(get_depend_conflic_aux(_visited,_manager,fn,_nnodes,_size,_var_low, _var_high, _reaches_one,"0")){
			(*_reaches_one)[strnode] = true;
			_var_low[index] = 1;
			if(indexE > index)
			{
				update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
			}
		}
	}
	//>> ROB : 23/12/2016 Does v reach the 1-terminal through low?

	ret = (_reaches_one->find(strnode) != _reaches_one->end()) ;

	delete[] R;
	delete[] f;
	delete[] fn;


	return ret;

}


void get_depen_conflic(DdManager* _manager, DdNode** _nodes, unsigned int _nnodes,unsigned int _num_vars, unsigned int* _var_low, unsigned int* _var_high)
{

	std::map<std::string,bool>* visited = new std::map<std::string,bool>();
	std::map<std::string,bool>* reaches_one = new std::map<std::string,bool>();

	get_depend_conflic_aux(visited,_manager,_nodes,_nnodes,_num_vars,_var_low,_var_high,reaches_one,"1");

	//<< ROB : 06/01/2017 Display visited nodes equivalent to count all nodes
	fprintf(stderr,"Dead core visited nodes %lu\n",visited->size());
	//>> ROB : 06/01/2017 Display visited nodes equivalent to count all nodes
}



void get_all_dependencies_conflicts (
				unsigned int* _var_high_2,unsigned int* _var_high_1,
				unsigned int* var_low_2,unsigned int* var_low_1,
				unsigned int**  all_vars_dependencies,
				unsigned int** all_vars_conflicts,unsigned int num_var, unsigned int var)
{
	unsigned int index;

	for (unsigned int i = 0; i < num_var; ++i){
		if (_var_high_1[i] && var_low_1[i] && i != var)
		{
			if (!_var_high_2[i] && var_low_2[i])
			{
				index = all_vars_conflicts[var][0];
				index++;
				all_vars_conflicts[var][0] = index;
				all_vars_conflicts[var][index] = i;
			}
			else if (_var_high_2[i] && !var_low_2[i] && i != var)
			{
				index = all_vars_dependencies[i][0];
				index++;
				all_vars_dependencies[i][0] = index;
				all_vars_dependencies[i][index] = var;
			}
		}
	}
}



feature_model_info* calc_dead_core_and_impact_exclusion(DdManager* _manager, DdNode** _nodes,unsigned int _nnodes, unsigned int _nvars)
{
	feature_model_info* ret = new feature_model_info;
	unsigned int* var_low_1 = (unsigned int*)calloc(_nvars,sizeof(unsigned int));
	unsigned int* var_high_1 =(unsigned int*)calloc(_nvars,sizeof(unsigned int));
    unsigned int* var_low_2 = (unsigned int*)calloc(_nvars,sizeof(unsigned int));
	unsigned int* var_high_2 = (unsigned int*)calloc(_nvars,sizeof(unsigned int));
    unsigned int **all_vars_dependencies = (unsigned int**)calloc(_nvars+1,sizeof(unsigned int*));
	unsigned **all_vars_conflicts  = (unsigned int**)calloc(_nvars+1,sizeof(unsigned int*));
	DdNode* tmp_nodes[_nnodes];



	//<< ROB : 26/12/2016 Get depend conflict to calculate dead,core,impact and exclusion set
	get_depen_conflic(_manager,_nodes,_nnodes,_nvars,var_low_1,var_high_1);
	ret->var_low = var_low_1;
	ret->var_high = var_high_1;
	//<< ROB : 26/12/2016 Get depend conflict to calculate dead,core,impact and exclusion set

    /*
	//<< ROB : 26/12/2016 calc dead and core features
    for(unsigned int i=0; i<_nvars; ++i){
		if (!(var_low_1[i] && var_high_1[i])){
			if(!var_low_1[i] && var_high_1[i] ){
				ret->core.push_back(i);
			}else{
				ret->dead.push_back(i);
			}
		}
    }
	//>> ROB : 26/12/2016 calc dead and core features

    //<< ROB : 26/12/2016 calc impact and exclusion set
    for(unsigned int i=0;i<_nvars;i++){
    	all_vars_dependencies[i] = (unsigned int*)calloc(_nvars+1,sizeof(unsigned int));
    	all_vars_conflicts[i] =  (unsigned int*)calloc(_nvars+1,sizeof(unsigned int));
    }
    for(unsigned int i=0;i<_nvars;i++){
    	//Variable feature --> not core and not dead
    	if(var_high_1[i] && var_low_1[i]){
    		//<< ROB : 26/12/2016 Set var low and hight to 0
    		for(unsigned int j=0;j<_nvars;j++){
    			var_high_2[j] = 0;
    			var_low_2[j] = 0;
    		}
    		//<< ROB : 26/12/2016 Add restriction always to the first function why?
    		tmp_nodes[0] = Cudd_bddAnd(_manager,_nodes[0], Cudd_bddIthVar(_manager,i));
    		for(unsigned int j=1;j<_nnodes;j++){
    			tmp_nodes[j] = _nodes[j];
    		}
    		if(tmp_nodes[0] != Cudd_Not(Cudd_ReadOne(_manager))){
    			get_depen_conflic(_manager,tmp_nodes,_nnodes,_nvars,var_low_2,var_high_2);
				get_all_dependencies_conflicts(var_high_2, var_high_1, var_low_2, var_low_1, all_vars_dependencies, all_vars_conflicts, _nvars, i);

    		}
    	}
    }

    std::list<unsigned int>* var_list;
    unsigned int index;
    for(unsigned int i=0;i<_nvars;i++){
    	if(all_vars_conflicts[i][0]>0){
    		for(unsigned int j=1;j<=all_vars_conflicts[i][0];j++){
    			index = all_vars_conflicts[i][j];
    			if(ret->exclusion_set.find(i) == ret->exclusion_set.end()){
    				var_list = new std::list<unsigned int>();
    				ret->exclusion_set[i] = var_list;
    			}
    			var_list = ret->exclusion_set[i];
    			var_list->push_back(index);
    		}
    	}
    	if(all_vars_dependencies[i][0] > 0 ){
    		for(unsigned int j=1;j<=all_vars_dependencies[i][0];j++){
    			index = all_vars_dependencies[i][j];
    			if(ret->impact_set.find(i) == ret->impact_set.end()){
    				var_list = new std::list<unsigned int>();
    				ret->impact_set[i] = var_list;
    			}
    			var_list = ret->impact_set[i];
    			var_list->push_back(index);
    		}
    	}
    }
    //>> ROB : 26/12/2016 calc impact and exclusion set

    //<< ROB : 27/12/2016 add dead and core to exclusion and impact set for all features
    for(unsigned int i=0;i<_nvars;i++)
    {
    	if(ret->exclusion_set.find(i) == ret->exclusion_set.end()){
    		var_list = new std::list<unsigned int>();
    		ret->exclusion_set[i] = var_list;
    	}
    	var_list = ret->exclusion_set[i];
    	for(std::list<unsigned int>::iterator it = ret->dead.begin(); it != ret->dead.end();it++)
    	{
    		if( (*it) == i )
    		{
    			for(unsigned int j=0;j<_nvars;j++)
    			{
    				var_list->push_back(j);
    			}
    		}else
    		{
    			var_list->push_back(*it);
    		}
    	}
    	if(ret->impact_set.find(i) == ret->impact_set.end())
    	{
    		var_list = new std::list<unsigned int>();
    		ret->impact_set[i] = var_list;
    	}
    	var_list = ret->impact_set[i];
    	if( std::find(ret->dead.begin(),ret->dead.end(),i) == ret->dead.end() )
    	{
        	for(std::list<unsigned int>::iterator it = ret->core.begin(); it != ret->core.end();it++)
        	{
        		unsigned int core_feature = (*it);
        		if( i != (*it))
        		{
        			var_list->push_back(i);
        		}else
        		{
        			for(unsigned j=0;j<_nvars;j++)
        			{
        				var_list->push_back(j);
        			}
        		}
        	}
    	}
    }
    //<< ROB : 27/12/2016 add dead to exclusion set for all features
    */
    return ret;
}




bool get_depend_conflic_aux_only_one(
		std::map<std::string,bool>* _visited,
		DdManager* _manager,
		DdNode* _f,
                                     unsigned int _size,unsigned int* _var_low, unsigned int* _var_high, std::map<std::string,bool>* _reaches_one,std::string _direction)
{

	DdNode *F,*fv,*fvn,*one;

	unsigned int index,indexT,indexE;


	F = Cudd_Regular (_f);
	one = DD_ONE(_manager);
	index =  get_index(_manager,F);
	std::string strnode = get_pointer(_manager,F,_direction);
    
    

	if(_visited->find(strnode) != _visited->end()){
		return (*_reaches_one)[strnode];
	}


	if(!cuddIsConstant(F)){
        
    
        //<< ROB 19/01/2017 Don't set visited R2 reduced nodes
        (*_visited)[strnode] = true;
        
		fv = cuddT(F);
		fvn = cuddE(F);
		if(Cudd_IsComplement(_f)){
			fv  = Cudd_Not(fv);
			fvn = Cudd_Not(fvn);
		}
		indexT = get_index_regular(_manager,fv);
		indexE = get_index_regular(_manager,fvn);
		//does v reach the 1-terminal throwgh high?
		if( one == fv )
		{
			_var_high[index] = 1;
			(*_reaches_one)[strnode] = true;
			if(indexT > index )
			{
				update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
			}
		}else{
			//keep searching
			if(Cudd_Not(one) != fv ){
				if(get_depend_conflic_aux_only_one(_visited,_manager,fv,_size,_var_low,_var_high,_reaches_one,"1")){
					(*_reaches_one)[strnode] = true;
					_var_high[index] = 1;
					if(indexT > index )
					{
						update_reduced_nodes(index,indexT,_var_low,_var_high,_size);
					}
				}
			}
		}

		//does v reach the 1-terminal throwgh low?
		if(one == fvn)
		{
			_var_low[index] = 1;
			(*_reaches_one)[strnode] = true;
			if(indexE > index )
			{
				update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
			}

		}
		else
		{
			//keep searching
			if(Cudd_Not(one) != fvn )
			{
				if(get_depend_conflic_aux_only_one(_visited,_manager,fvn,_size,_var_low,_var_high,_reaches_one,"0")){
					(*_reaches_one)[strnode] = true;
					_var_low[index] = 1;
					if(indexE > index )
					{
						update_reduced_nodes(index,indexE,_var_low,_var_high,_size);
					}
				}
			}
		}
	}
	return _reaches_one->find(strnode) != _reaches_one->end();
}


feature_model_info* calc_dead_core_and_impact_exclusion_only_one(DdManager* _manager, DdNode* _node, unsigned int _nvars)
{
	feature_model_info* ret = new feature_model_info;
	unsigned int* var_low = (unsigned int*)calloc(_nvars,sizeof(unsigned int));
	unsigned int* var_high =(unsigned int*)calloc(_nvars,sizeof(unsigned int));
	std::map<std::string,bool>* visited = new std::map<std::string,bool>();
	std::map<std::string,bool>* reaches_one = new std::map<std::string,bool>();


	get_depend_conflic_aux_only_one(
			visited,
			_manager,
			_node,
			_nvars,var_low,var_high,reaches_one,"1");

	ret->var_high = var_high;
	ret->var_low = var_low;


	//<< ROB : 06/01/2017 Display visited nodes equivalent to count all nodes
	fprintf(stderr,"Dead core visited nodes %lu\n",visited->size());
	//>> ROB : 06/01/2017 Display visited nodes equivalent to count all nodes


	return ret;

}

