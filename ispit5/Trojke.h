#pragma once
#ifndef TROJKE_H
#define TROJKE_H

#include <vector>
#include <algorithm>

template<typename T>
class Trojke {
public:
	std::vector<std::vector<T>> tr;
	Trojke() {};
	void brisiTrojku(int);
	void dodajTrojku(std::vector<T>&);
	int brojTrojki() const;
	void sortiraj(int);
	void printTrojke() const;
};

template<typename T> void Trojke<T>::brisiTrojku(int index) {
	tr.erase(tr.begin() + index);
}

template<typename T> void Trojke<T>::dodajTrojku(std::vector<T>& t) {
	if(t.size() == 3) tr.push_back(t);
}

template<typename T> int Trojke<T>::brojTrojki() const {
	return tr.size();
}

template<typename T> void Trojke<T>::sortiraj (int index) {
	std::sort(tr.begin(), tr.end(), sortBy);
}

template<typename T> void Trojke<T>::printTrojke() const {
	for (int i = 0; i < tr.size(); ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << tr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
}

#endif // !TROJKE_H
