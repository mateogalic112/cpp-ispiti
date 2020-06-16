#pragma once
#ifndef WORKINGFILE_H
#define WORKINGFILE_H

#include"FileInterface.h"

#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include "E.h"

class WorkingFile : public FileInterface {
	std::string fileName;
	std::ifstream f;
	std::ofstream of;
public:
	WorkingFile(std::string s) : fileName(s) {};
	void openFile(bool);
	void closeFile(bool);
	void readFile();
	void writeFile(std::string);
};

void WorkingFile::openFile(bool reading) {
	reading ? f.open(fileName) : of.open(fileName);
	if (reading) {
		if (!f.is_open()) throw E();
	} else {
		if (!of.is_open()) throw E();
	}
	std::cout << "File " << fileName << " Opened!" << std::endl;
}

void WorkingFile::closeFile(bool reading) {
	reading ? f.close() : of.close();
	std::cout << "File " << fileName << " Closed!" << std::endl;
}

void WorkingFile::readFile() {
	while (!f.eof()) {
		std::string item;
		f >> item;
		std::cout << item << endl;;
	}
}

void WorkingFile::writeFile(std::string s) {
	of << s << endl;
}

#endif // !WORKINGFILE_H
