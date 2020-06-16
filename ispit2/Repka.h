#pragma once
#ifndef REPKA_H
#define REPKA_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Repka {
public:
	char grupa;
	int utakmice, pobjede, porazi, nerjeseni, bodovi;
	string ime, golRazlika;

	bool operator< (Repka& other) {
		return bodovi > other.bodovi;
	}

	vector<Repka> napuniVector(string fileName) {
		vector<Repka> repke;
		ifstream f(fileName);
		while (!f.eof()) {
			Repka r;
			f >> r.ime >> r.grupa >> r.utakmice >> r.pobjede >> r.porazi >> r.nerjeseni
				>> r.golRazlika >> r.bodovi;
			repke.push_back(r);
		}
		return repke;
	}

	void sortirajVector(vector<Repka>& r) {
		sort(r.begin(), r.end());
	}

	void printajVector(vector<Repka>& r) const {
		for (int i = 0; i < r.size(); ++i) {
			cout << r.at(i).ime << " " << r.at(i).bodovi << endl;
		}
	}
};

#endif // !REPKA_H
