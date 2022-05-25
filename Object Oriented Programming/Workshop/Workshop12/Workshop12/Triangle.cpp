#include "Triangle.h"

Triangle::Triangle(
	int x, int y, const String& color,
	double aLength, double bLength,
	float aAngle)
	:Shape(x, y, color), 
	aLength(aLength), bLength(bLength), aAngle(aAngle) {}

double Triangle::getArea() const {
	return aLength * bLength * sin(aAngle) / 2;
}

void Triangle::getInfo() const {
	std::cout << "Triangle" << std::endl;
}