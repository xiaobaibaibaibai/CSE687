// Executive.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "../DirExplorer-Naive/DirExplorerN.h"
#include "../Utilities/StringUtilities/StringUtilities.h"
#include "../Utilities/CodeUtilities/CodeUtilities.h"

using namespace Utilities;
using namespace FileSystem;

int main(int argc, char *argv[])
{
	ProcessCmdLine pcl(argc, argv);

	if (pcl.parseError())
	{
		pcl.usage();
		std::cout << "\n\n";
		return 1;
	}

	DirExplorerN de(pcl.path());
	for (auto patt : pcl.patterns())
	{
		de.addPattern(patt);
	}

	de.recurse();
	de.search(); // this function search and call a find() function to print all path

	std::vector<std::string> result = de.getFileCollection();
	for (std::string s : result) {
		std::cout << s << '\n';
	}

	std::cout << "\n\n";
	getchar();
	return 0;
}
