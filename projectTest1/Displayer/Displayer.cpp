#include "Displayer.h"
#include <iostream>

int main() {
	std::string browser = "c:/Program Files (x86)/Google/Chrome/Application/chrome.exe";
	std::string command = "-new window C:/Users/wentan/CSE687/ENB687/projectTest1/Displayer/htmls/c1.html";

	Displayer p(browser);
	

	p.addCommand(command);


	return 0;
}