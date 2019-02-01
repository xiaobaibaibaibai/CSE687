// Executive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Executive.h"

int main(int argc, char *argv[])
{	
	Execute exe(argc, argv, "../convertedPages");
	exe.displayHtml();

	std::cout << "\n\n";
	getchar();
	return 0;
}
