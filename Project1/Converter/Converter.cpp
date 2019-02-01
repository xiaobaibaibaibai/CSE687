/////////////////////////////////////////////////////////////////////
// Executive.cpp								                   //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////

#include "Converter.h"

int main() {
	// using Converter.cpp and Converter.h to test
	std::vector<std::string> codePath = {
		"../Converter/Converter.cpp",
		"../Converter/Converter.h",
	};
	std::string savePath = "../Converter";

	ConverterHtml con(codePath, savePath);
	con.generateHtml();

	std::vector<std::string>savedPath = con.getHtmlPaths();
	for (std::string p : savedPath) {
		std::cout << p << std::endl;
	}

	return 0;
}