#pragma once
#ifndef DICT_H
#define DICT_H

#include <vector>
#include <string>
#include <iterator>
#include <fstream>

using namespace std;

#include "E.h"

struct Pair {
	string cro, eng;
};

class Dict {
public:
	vector<Pair> p;
	void read(string);
	string translate(string);
};

void Dict::read(string fileName) {
	ifstream f(fileName);
	while (!f.eof()) {
		Pair pair;
		f >> pair.cro >> pair.eng;
		p.push_back(pair);
	};
}

string Dict::translate(string word) {
	for (auto it = p.begin(); it != p.end(); ++it) {
		if ((*it).eng.find(word) != string::npos) {
			return (*it).cro;
		}
		else if ((*it).cro.find(word) != string::npos) {
			return (*it).eng;
		} 
	}
	throw E();
}

#endif // !DICT_h
