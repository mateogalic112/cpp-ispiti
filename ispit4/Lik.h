#pragma once
#ifndef LIK_H
#define LIK_H

class Lik {
public:
	virtual double area() = 0;
	virtual ~Lik() = 0;
};

Lik::~Lik() {};

#endif // !
