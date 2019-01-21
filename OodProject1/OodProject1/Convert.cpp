#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	ifstream readFile("test.cpp");
	string str;
	string file_contents;
	ofstream writeFile("test.cpp.html");

	if (writeFile.is_open()) {
		writeFile << "<!DOCTYPE html><html><head></head><body><pre>";
	}

	if (readFile.is_open()) {
		while (getline(readFile, str)) {
			//writeFile << str;
			file_contents += str;
			file_contents.push_back('\n');
		}
		readFile.close();
	}
	writeFile << file_contents;
	writeFile << "</span></body></html>";
	writeFile.close();

	/*getchar();
	getchar();*/
}