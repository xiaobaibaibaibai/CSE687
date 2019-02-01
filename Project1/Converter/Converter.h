#pragma once
/////////////////////////////////////////////////////////////////////
// Converter.h								                       //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 *  This package provides a class, ConverterHtml, which converts all 
 *  files to htmls and save to given folder  
 *
 *
 * Maintenance History:
 * --------------------
 * ver 1.0 : 31 Jan 2019
 * - first release
 *
*/

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class ConverterHtml
{
public:
	ConverterHtml(const std::vector<std::string> files_path_, const std::string save_path_);
	
	// convert functions
	void generateHtml();
	std::string convertCode(std::ifstream &readFile);
	
	// store paths path
	void collectHtmlPaths(std::string fullPath, std::string fileName);
	std::vector<std::string> getHtmlPaths();
	
private:
	std::vector<std::string> files_path;
	std::vector<std::string> htmls_path;
	std::string save_path;
};

ConverterHtml::ConverterHtml(const std::vector<std::string> files_path_, const std::string save_path_) {
	files_path = files_path_;
	save_path = save_path_;
}

//----< read cpp or header file and create a html to write>-------------------
void ConverterHtml::generateHtml() {
	for (std::string path : files_path) {
		std::ifstream readFile(path);
		if (readFile.is_open()) {
			std::size_t found = path.find_last_of("/\\");
			std::string fileName = path.substr(found + 1);
			std::ofstream writeFile(save_path + "/" + fileName + ".html");
			if (writeFile.is_open()) {
				writeFile << convertCode(readFile);
				writeFile.close();
				collectHtmlPaths(save_path, fileName);
			}
			else {
				std::cout << "write file: " << save_path << fileName << " cannot be opened" << '\n';
			}
			readFile.close();
		}
		else {
			std::cout << "read file: " << path << " cannot be opened" << '\n';
		}
	}
}

//----< convert cpp or header to a html>-------------------
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

//----< collect the paths of all converted file >-------------------
void ConverterHtml::collectHtmlPaths(std::string fullPath, std::string fileName) {
	htmls_path.push_back(fullPath+"/"+fileName+".html");
}

//----< return paths of collocted files>-------------------
std::vector<std::string> ConverterHtml::getHtmlPaths() {
	if (htmls_path.size() == 0) {
		std::cout << "none htmls are generated" << std::endl;
		return {};
	}
	return htmls_path;
}