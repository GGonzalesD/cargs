#include <iostream>
#include <list>
#include <vector>

namespace carg{

struct SParameter{
	// Struct used to build a Parameter
	std::string name;
	int limit;
};

std::vector<std::string> getNames(std::string);

class Parameter{
	std::string name;
	std::vector<std::string> values;
	int limit;

public:
	Parameter(std::string, int, std::vector<std::string>);
	Parameter(SParameter);
	Parameter();
	void addValue(std::string);
	bool full();
	bool empty();
	bool testName(std::string);

	void show();
};

}

