#pragma once
/////////////////////////////////////////////////////////////////////
// Executive.h								                       //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 * -------------------
 * DirExplorerN provides a class, Execute, that use a DirExplorerN 
 * instance, a Converter instance, a Displayer instance to search 
 * file at a specified path and convert all files in specified folder
 * to htmls and save into another specified folder.
 *
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


