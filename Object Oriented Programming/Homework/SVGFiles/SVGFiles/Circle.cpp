#include "Circle.h"

Circle::Circle(int x, int y, double radius)
	: Shape() {
	center.x = x;
	center.y = y;
	this->radius = radius;
}

Shape* Circle::clone() const {
	return new Circle(*this);
}

void Circle::translate(int x, int y) {
	center.translate(x, y);
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