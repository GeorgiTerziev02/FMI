#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, const String& color, double aLength, double bLength)
	:Shape(x, y, color), aLength(aLength), bLength(bLength) { }

double Rectangle::getArea() const {
	return aLength * bLength;
}

void Rectangle::getInfo() const {
	std::cout << "Rectangle" << std::endl;
}