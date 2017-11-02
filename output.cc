#include "output.h"
#include <algorithm>
#include <regex>
#include <list>


int get_max_nodes(std::vector<BDD>& _output, unsigned long& _total_nodes){

  int ret=0;
  int tmp;
  _total_nodes = 0;
  for(std::vector<BDD>::iterator it=_output.begin(); it != _output.end(); it++ ){
    tmp = Cudd_DagSize((*it).getNode());
    if (tmp > ret ) {
        ret = tmp;
    }
    _total_nodes = _total_nodes + tmp;
  }
  //std::cerr<<"total nodes"<<total<<std::endl;
  return ret;

}


void print_output(int _nvars,std::string _file,std::string _type, Cudd& _mgr,std::vector<BDD>& _output, bool _procesed, BDD* _function, bool _get_total)
{
	
	unsigned long total_nodes=-1;
	int max_nodes=-1;
    if(_procesed){
	    max_nodes = get_max_nodes(_output,total_nodes);
	    if(_get_total && _function != NULL ){
	        total_nodes = Cudd_DagSize(_function->getNode());
	    }
	}
	std::cout<<_file<<"\t"<<_type<<"\t"<<max_nodes<<"\t"<<total_nodes<<std::endl;
}

double get_user_time()
{
	struct rusage usage;
	double ret=0;
	
	getrusage(RUSAGE_SELF,&usage);
	ret = usage.ru_utime.tv_usec / 1000000.00 + usage.ru_utime.tv_sec;
	
	return ret;

}

double get_diftime(double _ts, double _te)
{
	double ret = _te -_ts;
	return ret;
}

void writeSize(std::string _file_name, std::string _function_file, std::string _order, std::vector<unsigned long>& _count_nodes, std::vector<unsigned long> _count_id)
{
    std::ofstream fd;
    int i=0;

    fd.open(_file_name.c_str(),std::ios::out | std::ios::app);

    for(int i=0; i < _count_nodes.size(); i++ )
    {
        fd<<_function_file<<"\t"<<_order<<"\t"<<i<<"\t"<<_count_id[i]<<"\t"<<_count_nodes[i]<<std::endl;
    }

    fd.close();
}


double countMinterms(Cudd& _mgr,BDD& _node)
{
    double ret = 0.0;
    FILE *fd = fopen(MINTERMS_FILE,"w");
    std::string line;

    _mgr.SetStdout(fd);
    _node.PrintMinterm();
    fclose(fd);
    _mgr.SetStdout(stdout);

    std::ifstream ffd(MINTERMS_FILE);
    if(ffd.is_open()){
        while (getline(ffd,line)){
            if(line.find("-") != std::string::npos)
            {
                double tmp = 0;
                for(int i=0;i<line.size();i++){
                    if (line[i] == '-'){
                        tmp = tmp + 1;
                    }
                }
                ret = ret + pow(2.0,tmp);
            }else{
                ret = ret + 1.0;
            }
            //std::cout<<line<<std::endl;
        }
    }
    ffd.close();


    return ret;
}


std::vector<std::string> split(const std::string& str, const std::string& delim)
{
    std::vector<std::string> tokens;
    size_t prev = 0, pos = 0;
    do
    {
        pos = str.find(delim, prev);
        if (pos == std::string::npos) pos = str.length();
        std::string token = str.substr(prev, pos-prev);
        if (!token.empty()) tokens.push_back(token);
        prev = pos + delim.length();
    }
    while (pos < str.length() && prev < str.length());
    return tokens;
}

std::string ltrim( std::string str ) {
    return std::regex_replace( str, std::regex("^\\s+"), std::string("") );
}

std::string rtrim( std::string str ) {
    return std::regex_replace( str, std::regex("\\s+$"), std::string("") );
}

std::string trim( std::string str ) {
    return ltrim( rtrim( str ) );
}


double  auxiliarTotalSymmetric(Cudd& _mgr, BDD& _bdd, unsigned int* _symmetrics_pairs,  unsigned int _current_variable, unsigned int _total_nodes )
{
    double ret=0;
    if(_current_variable + 1 < _total_nodes)
    {

        for(unsigned int i= _current_variable + 1 ; i < _total_nodes; i++)
        {
            ret = ret + 1;
            if(Cudd_VarsAreSymmetric(_mgr.getManager(),_bdd.getNode(),i,_current_variable))
            {
                (*_symmetrics_pairs) = (*_symmetrics_pairs) + 1;
            }
        }
        ret = ret + auxiliarTotalSymmetric(_mgr,_bdd,_symmetrics_pairs,_current_variable+1,_total_nodes);
    }
    return ret;
}



std::string totalSymmetric(Cudd& _mgr,BDD& _bdd, unsigned int _total_nodes)
{
    std::string ret = "";
    char buf[100];
    unsigned int symmetrics_pairs;

    double total = auxiliarTotalSymmetric(_mgr, _bdd, &symmetrics_pairs, 0, _total_nodes);

    sprintf(buf,"%g",symmetrics_pairs / total * 100);

    ret = buf;


    return ret;
}


std::string totalSymmetric_Old(Cudd& _mgr, unsigned int _total_nodes)
{
    std::string ret = "";

    //<< ROB: 26/11/2016 Save symmetric information
    FILE* fd = fopen(SYMMETRIC_FILE,"w");
    Cudd_SetStdout(_mgr.getManager(),fd);
    Cudd_SymmProfile(_mgr.getManager(),0,_total_nodes-1);
    fclose(fd);
    Cudd_SetStdout(_mgr.getManager(),fd);
    //<< ROB: 26/11/2016 Save symmetric information

    std::ifstream fs(SYMMETRIC_FILE);
    std::string line;
    bool found=false;
    while(!found && std::getline(fs,line))
    {
        if(line.find("Total Symmetric") != std::string::npos)
        {
            //std::cout<<"linefound:"<<line<<std::endl;
            std::vector<std::string> values = split(line,"=");
            ret = trim(values[1]);
            found = true;
        }
    }
    fs.close();


    return ret;

}
