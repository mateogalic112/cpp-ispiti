#pragma once
#ifndef KRUG_H
#define KRUG_H

#include "Lik.h"

class Krug : public Lik{
	double radius;
public:
	Krug(double r) : radius(r) {};
	double area() { return 2 * radius * 3.14; }
};

#endif // !KRUG_H
