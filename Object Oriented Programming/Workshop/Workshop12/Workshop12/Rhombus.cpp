#include "Rhombus.h"

Rhombus::Rhombus(int x, int y, const String& color, double aLength, float angle)
	:Shape(x, y, color), aLength(aLength), angle(angle) {}

double Rhombus::getArea() const {
	return aLength * aLength * sin(angle);
}

void Rhombus::getInfo() const {
	std::cout << "Rhombus" << std::endl;
}