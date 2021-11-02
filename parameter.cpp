#include "xargs/parameter.hpp"

namespace carg{

std::vector<std::string> getNames(std::string name){
	std::vector<std::string> names = std::vector<std::string>();
	std::string tmp = "";

	for(size_t i=0; i<name.size(); i++){
		if(name.at(i) == '='){
			names.push_back(tmp);
			tmp = "";
		}else{
			tmp.push_back(name.at(i));
		}
	}
	if(tmp.size() > 0)
		names.push_back(tmp);

	return names;
}

Parameter::Parameter(){
	name = "";
	limit = -1;
	values = std::vector<std::string>();
}

Parameter::Parameter(SParameter sParameter){
	name = sParameter.name;
	limit = sParameter.limit;
	values = std::vector<std::string>();
}

Parameter::Parameter(std::string _name, int _limit, std::vector<std::string> _values){
	name = _name;
	limit = _limit;
	values = _values;
}

bool Parameter::testName(std::string _name){
	return name.compare(_name) == 0;	
}

void Parameter::addValue(std::string _value){
	if( limit == -1 || values.size() < limit )
		values.push_back(_value);
}

bool Parameter::full(){
	return values.size() >= limit;
}

bool Parameter::empty(){
	return values.size() == 0;
}

void Parameter::show(){
	printf("[%s]: ", name.data());
	if(values.size() > 0)
	for(size_t i=0; i<values.size(); i++)
		printf("\"%s\" ", values[i].data());
	else
		printf("None");
	printf("\n");
}


}
