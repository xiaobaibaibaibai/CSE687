#pragma once

#include <iostream>
#include <vector>
#include "../Process/Process.h"


class Displayer
{
public:
	Displayer(const std::string& browserPath, const std::vector<std::string>& htmlsPath);
	void displayPage();
	std::vector<std::string> getHtmlDirectory();
	

private:
	std::string browser;
	Process p;
	std::vector<std::string> urls;
};


Displayer::Displayer(const std::string& browserPath, const std::vector<std::string>& htmlsPath) {
	browser = browserPath;
	urls = htmlsPath;
	p.application(browser);
}


void Displayer::displayPage() {
	for (std::string url : urls) {
		p.commandLine("--new-window " + url);
		p.create();
		CBP callback = [&url]() { std::cout << "\n --- process is exited----"; };
		p.setCallBackProcessing(callback);
		p.registerCallback();

		WaitForSingleObject(p.getProcessHandle(), INFINITE);

	}
	std::cout << "\n  after OnExit";
	std::cout.flush();
	char ch;
	std::cin.read(&ch, 1);
}


std::vector<std::string> Displayer::getHtmlDirectory() {
	return urls;
}






