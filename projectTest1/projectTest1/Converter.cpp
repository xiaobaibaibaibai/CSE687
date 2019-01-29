/////////////////////////////////////////////////////////////////////
// Proj1Helper.cpp - will become webified                          //
//                                                                 //
// Jim Fawcett, CSE687 - Object Oriented Design, Spring 2019       //
/////////////////////////////////////////////////////////////////////



#include "Converter.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#ifdef TEST_PROCESS
int main(int argc, char* argv[]) {
	std::string line;
	std::vector<std::string> all_args;
	all_args.assign(argv + 1, argv + argc);


	for (size_t i = 1; i < all_args.size(); i++) {
		std::cout << all_args[i] << std::endl;
		
		std::ifstream readFile(all_args[i]);
		if (readFile.is_open()) {
			std::string fileName = all_args[i];
			std::ofstream writeFile("../outputhtml/" + fileName + ".html");
			if (writeFile.is_open()) {
				std::string beforePre = "<!Doctype html><head><style>"
					"body{padding: 15px 40px;font-family: Consolas;font-size: 1.25em;font-weight: normal;}"
					"</style></head><body><h3>Project #1 helper</h3><pre>";
				writeFile << beforePre;
				std::string cppCode = "";
				while (getline(readFile, line)) {
					cppCode = cppCode + line + '\n';
				}
				writeFile << cppCode;
				writeFile << "</pre></body></html>";
				writeFile.close();
			}
			readFile.close();
		}
		
	}
	return 0;
}

#endif



