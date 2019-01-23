#include <iostream>
#include <string>
#include <vector>
#include <regex>


bool verifyName(std::string fnames[]) {
	std::regex txt_regex("[\\-\\w]+\\.(cpp|h)");
	
	std::cout << fnames[0] << std::endl;
	
	return true;
}

int main12(int argc, char *argv[])
{
	std::string current_exec_name = argv[0];
	std::vector<std::string> all_args;
	if (argc < 2) {
		std::cout << "not have file name" << std::endl;
	} else {
		all_args.assign(argv + 1, argv + argc);
	}

	for (auto arg : all_args) {
		std::cout << arg << "  ";
	}
	std::cout << std::endl;


	// Simple regular expression matching
	/*std::string fnames[] = { 
		"foo.cpp", "bar.h", 
		"baz.cppp", "baz.cp", "zoidberg.hh",
		"Baz.cpp", "bAz.cpp", "Xoidberg.h", "zoidberG.h",
		"01.cpp", "ab02.h", "03sdf.cpp", "kk04l.cpp",
		"01-aa.cpp", "02_aa.cpp", "03_-.cpp", "-04.cpp", "_05.cpp", "-_06.cpp",
		"bazcpp", "zoidbergh" 
	};
	std::cout << argc << std::endl;

	if (verifyName(fnames)) {
		std::cout << "end" << std::endl;
	}*/
	

	/*std::regex txt_regex("[\\-\\w]+\\.(cpp|h)");

	for (const auto &fname : fnames) {
		if (std::regex_match(fname, txt_regex)) {
			std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
		}
	}*/
	

	getchar();
	getchar();
	return 0;
}