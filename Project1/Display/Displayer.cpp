/////////////////////////////////////////////////////////////////////
// Executive.cpp								                   //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////

#include "Displayer.h"

int main() {
	std::string browser = "c:/Program Files (x86)/Google/Chrome/Application/chrome.exe";

	// some testing htmls
	std::vector<std::string> htmls = {
		"../Display/htmls/c1.html",
		"../Display/htmls/h1.html"
	};

	Displayer dis(browser, htmls);
	dis.displayPage();

	// print aviable htmls
	std::vector<std::string> urls = dis.getAllHtmlPaths();
	for (std::string url : urls) {
		std::cout << url << std::endl;
	}

	return 0;
}
