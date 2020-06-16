#pragma once
#ifndef DEQUECLASS_H
#define DEQUECLASS_H

#include <vector>

#include "E.h"

template<typename T>
class DequeClass {
	std::vector<T> deq;
	int maxSize, currSize;
public:
	DequeClass(int s) : maxSize(s), currSize(0) {};
	std::vector<T> getDeq() const { return deq; };
	void dodajNaKraj(T);
	void skiniSaPocetka();
};

template<typename T> void DequeClass<T>::dodajNaKraj(T t) {
	if (currSize == maxSize) throw E();
	deq.push_back(t);
	currSize++;
}

template<typename T> void DequeClass<T>::skiniSaPocetka() {
	if (currSize == 0) throw E();
	deq.erase(deq.begin());
	currSize--;
}

#endif // !DEQUECLASS_H
