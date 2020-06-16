#pragma once
#ifndef BASEPOINT_H
#define BASEPOINT_H

using namespace std;

struct Point {
	double x, y;
};

class BasePoint {
protected:
	double vx, vy;
	Point p;
public:
	// member functions
	void init() { p.x = 1; p.y = 1; }
	virtual void setVelocity() = 0;
	void move(double dt) { p.x = p.x + vx * dt; p.y = p.y + vy * dt; };
	void display() { cout << p.x << ", " << p.y << endl; }
};

#endif // !BASEPOINT_H
