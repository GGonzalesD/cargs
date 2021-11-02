#include "xargs/args.hpp"

namespace carg{


Args::Args(int args, const char** kargs, std::vector<SParameter> configparas){
	filename = kargs[0];

	insertParameter({"", -1});
	for(size_t i=0; i<configparas.size(); i++){
		if(checkParameter(configparas[i].name))
			insertParameter(configparas[i]);
	}

	size_t index = 0;
	for(int i=1; i<args; i++){
		if(index == 0){ // main case
			if(checkParameter(kargs[i])){
				std::vector<std::string> names = getNames(kargs[i]);
				if(names.size() > 1){
					int id = insertParameter({names[0], 1});
					for(size_t i=1; i<names.size(); i++)
						parameters[id].addValue(names[i]);

					if(!parameters[id].full())
						index = id;
				}else{
					int id = insertParameter({kargs[i], 0});
					if(!parameters[id].full())
						index = id;
				}

			}else{
				parameters[0].addValue(kargs[i]);
			}
		}else{
			if(parameters[index].full()){
				i--;
				index = 0;
			}else{
				parameters[index].addValue(kargs[i]);
			}
		}
	}
}

int Args::insertParameter(SParameter sParameter){
	if(!hasParameter(sParameter.name)){
		Parameter parameter(sParameter);
		parameters.push_back(parameter);
		return parameters.size()-1;
	}
	return getIndexParameter(sParameter.name);
}

int Args::getIndexParameter(std::string parameter){
	for(size_t i=0; i<parameters.size(); i++){
		if(parameters[i].testName(parameter))
			return i;
	}
	return -1;
}

bool Args::hasParameter(std::string parameter){
	for(size_t i=0; i<parameters.size(); i++){
		if(parameters[i].testName(parameter))
			return true;
	}
	return false;
}

bool Args::checkParameter(std::string parameter){
	if(parameter.length() < 2)
		return false;
	if(parameter.at(0) != '-')
		return false;
	for(size_t i=0; i<parameter.length(); i++)
		if(parameter.at(i) == ' ')
			return false;

	return true;	
}

void Args::show(){
	printf("Filename: %s\n", filename.data());
	for(size_t i=0; i<parameters.size(); i++){
		parameters[i].show();
	}
}

}
