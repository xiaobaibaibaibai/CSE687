#pragma once
/////////////////////////////////////////////////////////////////////
// Executive.h								                       //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * DirExplorerN provides a class, of the same name, that executes a
 * depth first search of a directory tree rooted at a specified path.
 * Each time it enters a directory, it invokes its member function
 * doDir, and for every file in that directory, it invokes doFile.
 *
 * We call this a "Naive Directory Explorer" because, while it carries
 * out its assigned responsibilities well, there is no way to change
 * what its doDir and doFile functions do, without changing the class
 * itself.  It would be much better to provide a mechanism to allow
 * a using application to supply this processing without changing
 * the Directory Navigator.
 *
 * Other projects in the DirectoryNavigator folder in Repository/Cpp
   do just that, in different ways.

 * - DirExplorer-Naive (this project):
 *     Implements basic processing well, but applications have to
 *     change its code to affect how files and directories are
 *     handled.
 * - DirExplorer-Template:
 *     Applications provide template class parameters to define file
 *     and directory processing.
 * - DirExplorer-Inheritance:
 *     Applications subclass DirExplorerI, overriding virtual functions
 *     doFile, doDir, and doQuit to define how files and directories
 *     are handled, and whether processing should terminate before
 *     visiting all directories.
 * - DirExplorer-Events:
 *     Applications use Event Interfaces, published by DirExplorerE,
 *     by subscribing event-handler functions, and control terminate
 *      processing using a plug-in interface.
 * - DirExplorer-Provider:
 *     Applications implement a file system provider that implements
 *     a Provider interface published by DirExplorerP.
 *
 * We'll be using the Repository/Cpp solution to illustrate techniques
 * for building flexible software.
 *
 * Required Files:
 * ---------------
 * DirExplorerN.h                    // DirExplorerN class
 * FileSystem.h, FileSystem.cpp      // Directory and Path classes
 * StringUtilities.h                 // Title function
 * CodeUtilities.h                   // ProcessCmdLine class
 * Displayer.h                       // Display class
 * Converter.h                       // Converter class
 *
 * Maintenance History:
 * --------------------
 * ver 1.0 : 31 Jan 2019
 * - first release
 *
*/

#include "../DirExplorer-Naive/DirExplorerN.h"
#include "../Utilities/StringUtilities/StringUtilities.h"
#include "../Utilities/CodeUtilities/CodeUtilities.h"
#include "../Converter/Converter.h"
#include "../Display/Displayer.h"
#include <iostream>
#include <string>
#include <vector>

using namespace Utilities;
using namespace FileSystem;

class Execute {
public:
	Execute(int argc, char** argv, const std::string savePath);
	std::vector<std::string> findMatchedFiles();
	std::vector<std::string> convertToHtml();
	void displayHtml();

private:
	int argc_ = 0;
	char** argv_;

	// the path of folder to save htmls 
	std::string savePath_;
};

//----< construct Execute instance with arguments >-----
Execute::Execute(int argc, char** argv, const std::string savePath) {
	argc_ = argc;
	argv_ = argv;
	savePath_ = savePath;
}

//----< find matched files in given forder >--------
std::vector<std::string> Execute::findMatchedFiles() {
	ProcessCmdLine pcl(argc_, argv_);
	if (pcl.parseError()) {	
		std::cout << "parseError \n\n";
		return {};
	}

	DirExplorerN de(pcl.path());
	for (auto patt : pcl.patterns()) {
		de.addPattern(patt);
	}
	de.recurse();
	de.search();
	return de.getFileCollection();
}

//----< convert every matched file to a html file >--------
std::vector<std::string> Execute::convertToHtml() {
	std::string savePath = FileSystem::Path::getFullFileSpec(savePath_);
	std::replace(savePath.begin(), savePath.end(), '\\', '/');
	std::vector<std::string> matedPath = findMatchedFiles();

	if (matedPath.size() == 0) {
		std::cout << "there are not matched files" << "\n";
		return {};
	}
	else {
		ConverterHtml con(matedPath, savePath);
		con.generateHtml();
		return con.getHtmlPaths();
	}
}

//----< dispaly all converted html >--------
void Execute::displayHtml() {
	std::vector<std::string> htmls = convertToHtml();
	if (htmls.size() == 0) {
		std::cout << "there are not converted files" << "\n";
	}
	else {
		Displayer dis(argv_[1], htmls);
		dis.displayPage();
	}
}


