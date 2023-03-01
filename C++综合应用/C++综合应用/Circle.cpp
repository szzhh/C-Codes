#include <iostream>
#include "Point.h"
#include "Circle.h"
using namespace std;
Circle::Circle(double a, double b, double r) :Point(a, b), radius(r) {}
void Circle::setRadius(double r) { radius = r; }
double Circle::getRadius() const { return radius; }
double Circle::area() const { return 3.14159 * radius * radius; }
ostream& operator<<(ostream& output, const Circle& c)
{
	output << "Center=[" << c.x << ", " << c.y << "], r=" << c.radius << ", area=" << c.area() << endl;
	return output;
}
