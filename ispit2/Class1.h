#pragma once
#ifndef CLASS1_H
#define CLASS1_H

#include "BasePoint.h"

class Class1 : public BasePoint{
public:
	Class1() {};
	void setVelocity() {
		vx = -p.y;
		vy = p.x;
	}
};

#endif // !CLASS1_H
