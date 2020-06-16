#pragma once
#ifndef CLASS2_H
#define CLASS2_H

#include "BasePoint.h"

class Class2 : public BasePoint {
public:
	Class2() {};
	void setVelocity() {
		vx = p.x;
		vy = p.y;
		std::cout << vx << std::endl;
	}
};

#endif // !CLASS2_H
