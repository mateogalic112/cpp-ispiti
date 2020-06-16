#pragma once
#ifndef POINT_H
#define POINT_H
	
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Point {
	T x, y;
public:
	Point(T a, T b) : x(a), y(b) {};
	friend double operator- (Point& a, Point& b) {
		return abs(sqrt(pow((b.x - a.x), 2) + pow((b.y - a.y), 2)));
	};
	friend ostream& operator<< (ostream& os, Point& p);
};

ostream& operator<< (ostream& os, Point<int>& p) {
	os << "(" << p.x << "," << p.y << ")";
	return os;
}

#endif // !POINT_H
