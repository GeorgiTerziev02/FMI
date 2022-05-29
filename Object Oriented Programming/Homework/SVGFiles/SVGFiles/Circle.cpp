#include "Circle.h"

Circle::Circle(int x, int y, double radius) {
	center.x = x;
	center.y = y;
	this->radius = radius;
}

void Circle::translate(int x, int y) {
	center.x += x;
	center.y += y;
}

bool Circle::isPointIn(int x, int y) const {
	return center.getDist(point(x, y)) <= radius;
}

double Circle::getArea() const {
	return radius * radius * 3.14;
}

double Circle::getPerimeter() const {
	return 2 * radius * 3.14;
}

void Circle::print() const {
	std::cout << "Circle" << std::endl;
}