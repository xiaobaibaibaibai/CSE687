#include "test.h"
#include <fstream>
#include <string>


test::test()
{
	std::ifstream file("Read.txt");
	std::string str;
	while (std::getline(file, str))
	{
		// Process str
	}
}


test::~test()
{
}
