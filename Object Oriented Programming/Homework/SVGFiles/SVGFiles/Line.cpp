#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2) {
	p1.x = x1;
	p1.y = y1;
	p2.x = x2;
	p2.y = y2;
}

Shape* Line::clone() const {
	return new Line(*this);
}

void Line::translate(int x, int y) {
	p1.translate(x, y);
	p2.translate(x, y);
}

bool Line::isPointIn(int x, int y) const {
	point point(x, y);

	// TODO: refactor
	return p1.getDist(point) + p2.getDist(point) == p1.getDist(p2);
}

double Line::getArea() const {
	return 0;
}

double Line::getPerimeter() const {
	return p1.getDist(p2);
}

void Line::print() const {
	std::cout << "Line" << std::endl;
}