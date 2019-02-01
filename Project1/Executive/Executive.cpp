/////////////////////////////////////////////////////////////////////
// Executive.cpp								                   //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////

#include "Executive.h"

int main(int argc, char *argv[])
{	
	Execute exe(argc, argv, "../convertedPages");
	exe.displayHtml();

	std::cout << "\n\n";
	getchar();
	return 0;
}
