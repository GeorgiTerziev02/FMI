#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, double width, double height, const String& fill, const String& stroke, int strokeWidth)
	:Shape(stroke, strokeWidth)
{
	point.x = x;
	point.y = y;
	this->width = width;
	this->height = height;
	this->fill = fill;
	type = TypeOfShape::RECTANGLE;
}

Shape* Rectangle::clone() const {
	return new Rectangle(*this);
}

void Rectangle::translate(int x, int y) {
	point.translate(x, y);
}

bool Rectangle::isPointIn(int x, int y) const {
	return point.x <= x && x <= point.x + width
		&& point.y <= y && y <= point.y + height;
}

bool Rectangle::isWithin(const Shape* shape) const {
	return shape->isPointIn(point.x, point.y)
		&& shape->isPointIn(point.x + width, point.y)
		&& shape->isPointIn(point.x, point.y + height)
		&& shape->isPointIn(point.x + width, point.y + height);
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
	std::cout << "rectangle " << point.x << " " << point.y 
		<< " width: " << width << " height: " << height
		<< " fill: " << fill << " stroke: " << stroke << " stroke width: " << strokeWidth << " "
		<< std::endl;
}

std::ostream& operator<<(std::ostream& out, const Rectangle& rect) {
	//<rect x = "1" y = "1" width = "1198" height = "398"
	//fill = "none" stroke = "blue" stroke - width = "2" / >
	return out << "<rect x=\"" << rect.point.x
		<< "\" y=\"" << rect.point.y
		<< "\" width=\"" << rect.width
		<< "\" height=\"" << rect.height
		<< "\" fill=\"" << rect.fill
		<< "\" stroke=\"" << rect.stroke
		<< "\" stroke-width=\"" << rect.strokeWidth
		<< "\" />";
}