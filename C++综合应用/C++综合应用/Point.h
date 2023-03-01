#pragma once
#include <iostream>
using namespace std;
class Point
{
public:
	Point(double x = 0, double y = 0);
	void setPoint(double, double);
	double getX() const { return x; }
	double getY() const { return y; }
	friend ostream& operator<<(ostream&, const Point&);
protected:
	double x, y;
};
