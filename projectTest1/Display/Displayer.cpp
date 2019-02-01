#include "Displayer.h"
#include <iostream>
#include <vector>
#include <string>

int main() {
	std::string browser = "c:/Program Files (x86)/Google/Chrome/Application/chrome.exe";
	/*std::vector<std::string> htmls = {
		"d:/Syracuse/CSE687/CSE687/projectTest1/Display/htmls/c1.html",
		"d:/Syracuse/CSE687/CSE687/projectTest1/Display/htmls/h1.html"
	};*/

	std::vector<std::string> htmls = {
		"D:/Syracuse/CSE687/CSE687/projectTest1/convertedPages/root1.cpp.html",
		"D:/Syracuse/CSE687/CSE687/projectTest1/convertedPages/root1.h.html"
	};

	Displayer dis(browser, htmls);
	dis.displayPage();
	

	return 0;
}
