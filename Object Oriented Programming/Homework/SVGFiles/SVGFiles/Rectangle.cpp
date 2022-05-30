#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, double width, double height) {
	point.x = x;
	point.y = y;
	this->width = width;
	this->height = height;
	type = TypeOfShape::Rectangle;
}

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}

void Rectangle::translate(int x, int y) {
	point.translate(x, y);
}

bool Rectangle::isPointIn(int x, int y) const {
	return point.x <= x && x <= point.x + width 
		&& point.y <= y && y <= point.y + width;
}

double Rectangle::getArea() const {
	return width * height;
}

double Rectangle::getPerimeter() const {
	return 2 * (height + width);
}

const char* Rectangle::getTypeString() const {
	return "Rectangle";
}

void Rectangle::print() const {
	std::cout << "Rectangle" << std::endl;
}