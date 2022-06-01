#include "Circle.h"

Circle::Circle(int x, int y, double radius, const String& fill, const String& stroke, int strokeWidth)
	: Shape(stroke, strokeWidth) 
{
	center.x = x;
	center.y = y;
	this->radius = radius;
	this->fill = fill;
	type = TypeOfShape::CIRCLE;
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

bool Circle::isWithin(const Shape* shape) const {
	return shape->isPointIn(center.x, center.y)
		&& shape->isPointIn(center.x + radius, center.y)
		&& shape->isPointIn(center.x, center.y + radius)
		&& shape->isPointIn(center.x - radius, center.y)
		&& shape->isPointIn(center.x, center.y - radius);
}

double Circle::getArea() const {
	return radius * radius * 3.14;
}

double Circle::getPerimeter() const {
	return 2 * radius * 3.14;
}

const char* Circle::getTypeString() const {
	return "Circle";
}

void Circle::print() const {
	std::cout << "circle " << center.x << " " << center.y << " " 
		<<"radius: " << radius << " fill: " << fill << " stroke: "
		<< stroke << " stroke width: " << strokeWidth << " "
		<< std::endl;
}

std::ostream& operator<<(std::ostream& out, const Circle& circle) {
	return out << "<circle cx=\"" << circle.center.x 
		<< "\" cy=\"" << circle.center.y
		<< "\" r=\"" << circle.radius
		<< "\" fill=\"" << circle.fill
		<< "\" stroke=\"" << circle.stroke
		<< "\" stroke-width=\"" << circle.strokeWidth
		<< "\" />";
}