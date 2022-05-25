#include "Circle.h"

Circle::Circle(int x, int y, const String& color, double diameter)
	:Shape(x, y, color), diameter(diameter) {}

double Circle::getArea() const {
	return (diameter / 2) * (diameter / 2) * 3, 14;
}

void Circle::getInfo() const {
	std::cout << "Circle" << std::endl;
}