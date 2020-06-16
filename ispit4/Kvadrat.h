#pragma once
#ifndef KVADRAT_H
#define KVADRAT_H

#include "Lik.h"

class Kvadrat :public Lik {
	double a;
public:
	Kvadrat(double a) : a(a) {};
	double area() { return a * a; }
};

#endif // !KVADRAT_H
