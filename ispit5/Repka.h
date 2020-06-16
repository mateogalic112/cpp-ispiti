#pragma once
#ifndef REPKA_H
#define REPKA_H

#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iostream>

class Repka {
public:
	char grupa;
	int utakmice, pobjede, porazi, nerjeseni, bodovi;
	std::string ime, golRazlika;
	Repka() 
	 : grupa('0'), utakmice(0), pobjede(0), porazi(0),
		nerjeseni(0), bodovi(0), ime(""), golRazlika("") {};

	bool operator< (Repka& other);

	std::vector<Repka> napuniVector(std::string);

	void sortirajVector(std::vector<Repka>&);

	void printajVector(std::vector<Repka>&) const;
};

bool Repka::operator< (Repka& other) {
	return grupa < other.grupa;
}


std::vector<Repka> Repka::napuniVector(std::string file) {
	std::vector<Repka> repke;
	std::ifstream f(file);
	while (!f.eof()) {
		Repka r;
		f >> r.ime >> r.grupa >> r.utakmice >> r.pobjede
			>> r.porazi >> r.nerjeseni >> r.bodovi >> r.golRazlika;
		repke.push_back(r);
	}
	return repke;
}

void Repka::sortirajVector(std::vector<Repka>& r) {
	std::sort(r.begin(), r.end());
	std::vector<std::vector<Repka>> grupe;
	int size = r.size();
	for (auto it = r.begin(); it != r.end(); it += 3) {
		std::vector<Repka> newR;
		newR.assign(it, it + 3);
		grupe.push_back(newR);
	}

}

void Repka::printajVector(std::vector<Repka>& r) const {
	for (auto it = r.begin(); it != r.end(); ++it) {
		std::cout << (*it).ime << std::endl;
	}
}


#endif // !REPKA_H
