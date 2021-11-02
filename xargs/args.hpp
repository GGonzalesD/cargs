#include <iostream>
#include <vector>
#include <cstdarg>
#include "parameter.hpp"

namespace carg{

class Args{
	std::string filename;
	std::vector<Parameter> parameters;

public:
	Args(int, const char**, std::vector<SParameter>);

	bool checkParameter(std::string);
	int insertParameter(SParameter);
	bool hasParameter(std::string);
	int getIndexParameter(std::string);

	void show();
};

}

