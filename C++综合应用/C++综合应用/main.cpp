#include <iostream>
#include "Point.h"
#include "Circle.h"
#include "Cylinder.h>
#include <stdlib.h"
using namespace std;
int main()
{
	system("color 3E");
	Cylinder cy1(3.5, 6.4, 5.2, 10);
	cout << "original cylinder:\nx=" << cy1.getX() << ", y=" << cy1.getY() << ", r="
		<< cy1.getRadius() << ", h=" << cy1.getHeight() << "\narea=" << cy1.area()
		<< ", volume=" << cy1.volume() << endl;
	cy1.setHeight(15);
	cy1.setRadius(7.5);
	cy1.setPoint(5, 5);
	cout << "\nnew cylinder:\n" << cy1;
	Point& pRef = cy1;
	cout << "\npRef as a Point:" << pRef;
	Circle& cRef = cy1;
	cout << "\ncRef as a Circle:" << cRef;
	return 0;
}
