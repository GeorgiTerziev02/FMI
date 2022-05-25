#include "Shape.h"

Shape::Shape(int x, int y, const String& color) {
	point.x = x;
	point.y = y;
	this->color = color;
}