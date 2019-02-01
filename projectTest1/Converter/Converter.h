#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

class ConverterHtml
{
public:
	ConverterHtml(const std::vector<std::string> files_path_, const std::string save_path_);

	void generateHtml();
	void collectHtmlPaths(std::string fullPath, std::string fileName);
	std::string convertCode(std::ifstream &readFile);
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


void ConverterHtml::collectHtmlPaths(std::string fullPath, std::string fileName) {
	htmls_path.push_back(fullPath+"/"+fileName+".html");
}

std::vector<std::string> ConverterHtml::getHtmlPaths() {
	return htmls_path;
}