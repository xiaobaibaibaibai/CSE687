#pragma once
/////////////////////////////////////////////////////////////////////
// Process.h								                       //
// ver 1.0                                                         //
// Wentan Bai, CSE687 - Object Oriented Design, Spring 2019        //
/////////////////////////////////////////////////////////////////////
/*
 * Package Operations:
 *  This package provides a class, Displayer, which calls a Process class 
 *  used to start named web processes.
 *
 * Required Files:
 * ---------------
 * Process.h                         // Process class
 *
 * Maintenance History:
 * --------------------
 * ver 1.0 : 31 Jan 2019
 * - first release
 *
*/

#include <iostream>
#include <vector>
#include "../Process/Process.h"


class Displayer
{
public:
	Displayer(const std::string& browserPath, const std::vector<std::string>& htmlsPath);
	void displayPage();
	std::vector<std::string> getAllHtmlPaths();

private:
	std::string browser;
	std::vector<std::string> urls;
};

//----< set browser path and file paths >-------------------
Displayer::Displayer(const std::string& browserPath, const std::vector<std::string>& htmlsPath) {
	browser = browserPath;
	urls = htmlsPath;
}

//----< add browser path to Process instance and use it to display htmls >-------------
void Displayer::displayPage() {
	Process p;
	p.application(browser);
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

//----< return all paths of html>----------------------
std::vector<std::string> Displayer::getAllHtmlPaths() {
	if (urls.size() == 0) {
		std::cout << "there are not htmls \n";
		return {};
	}
	else {
		return urls;
	}
}






