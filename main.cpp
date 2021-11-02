#include <iostream>
#include <cstdarg>
#include "xargs/args.hpp"


int main(int args, const char ** kargs){
	carg::Args cargs(args, kargs, {
		{"-test", 2},
		{"-file", 1}
	});

	std::cout << std::endl;
	cargs.show();

	return 0;
}