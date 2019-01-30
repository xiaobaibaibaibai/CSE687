#pragma once

#include <iostream>
#include "../Process/Process.h"

class Displayer
{
public:
	Displayer(const std::string& path, const int& i);
	void addCommand(const std::string& cmdLine);
	void displayPage();

private:
	std::string browser;
	Process p;
	int count;
};


Displayer::Displayer(const std::string& path, const int& i) {
	browser = path;
	count = i;
	p.application(browser);
}

void Displayer::addCommand(const std::string& cmdLine) {
	p.commandLine(cmdLine);
}

void Displayer::displayPage() {
	for (int i = 0; i < count; i++) {
		p.create();
		CBP callback = []() { std::cout << "\n  --- child process exited with this message ---"; };
		p.setCallBackProcessing(callback);
		p.registerCallback();

		WaitForSingleObject(p.getProcessHandle(), INFINITE);  // wait for created process to terminate

	}
	std::cout << "\n  after OnExit";
	std::cout.flush();
	char ch;
	std::cin.read(&ch, 1);
}





