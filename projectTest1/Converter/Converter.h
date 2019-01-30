#pragma once
/////////////////////////////////////////////////////////////////////
// DirExplorerN.h - Naive directory explorer                       //
// ver 1.3                                                         //
// Jim Fawcett, CSE687 - Object Oriented Design, Fall 2018         //
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
 * Other projects in this solution do just that, in different ways.

 * - DirExplorer-Naive:
 *     Implements basic processing well, but applications have to
 *     change its code to affect how files and directories are
 *     handled.
 * - DirExplorer-Template:
 *     Applications provide template class parameters to define file
 *      and directory processing.
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
 * We'll be using this solution to illustrate techniques for building
 * flexible software.
 *
 * Required Files:
 * ---------------
 * DirExplorerN.h, DirExplorerN.cpp
 * FileSystem.h, FileSystem.cpp      // Directory and Path classes
 * StringUtilities.h                 // Title function
 * CodeUtilities.h                   // ProcessCmdLine class
 *
 * Maintenance History:
 * --------------------
 * ver 1.4 : 29 Jan 2019
 * - Add two new functions to collect path and names which matches
 *	the regular expression of cpp and header file .
 * ver 1.3 : 19 Aug 2018
 * - Removed some options to make this version simple.  Those are
 *   implemented in the more advanced navigators, presented here.
 * ver 1.2 : 17 Aug 2018
 * - Moved method definitions to inlines, below the class declaration.
 * ver 1.1 : 16 Aug 2018
 * - Made no recursion default, added option /s for recursion.
 * ver 1.0 : 11 Aug 2018
 * - first release
 *
*/
#include <vector>
#include <iostream>
#include <fstream>
#include <string>



class ConverterHtml
{
public:
	ConverterHtml() {}
	~ConverterHtml() {}

	void openFile(std::vector<std::string> files_path, std::string save_path);
	std::string convertCode(std::ifstream &readFile);
};


void ConverterHtml::openFile(std::vector<std::string> files_path, std::string save_path) {
	for (std::string path : files_path) {
		std::ifstream readFile(path);
		if (readFile.is_open()) {
			std::size_t found = path.find_last_of("/\\");
			std::string fileName = path.substr(found + 1);
			std::ofstream writeFile(save_path + fileName + ".html");
			if (writeFile.is_open()) {
				writeFile << convertCode(readFile);
				writeFile.close();
			}
			else {
				std::cout << save_path << fileName << " cannot open" << '\n';
			}
			readFile.close();
		}
		else {
			std::cout << path << " cannot open" << '\n';
		}
	}
}

std::string ConverterHtml::convertCode(std::ifstream &readFile) {
	std::string html = "<!Doctype html><head><style>"
		"body{padding: 15px 40px;font-family: Consolas;font-size: 1.25em;font-weight: normal;}"
		"</style></head><body><h3>Project #1 helper</h3><pre>";
	html += '\n';
	std::string line;
	while (getline(readFile, line)) {
		for (char cha : line) {
			if (cha == '<')
				html += "&lt";
			else if (cha == '>')
				html += "&gt";
			else
				html += cha;
		}
		html += '\n';
	}
	html += "</pre></body></html>";;
	return html;
}
