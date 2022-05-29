#pragma once
#include "Shape.h"

class Circle : public Shape
{
	point center;
	double radius;
public:
	Circle(int x, int y, double radius);

	void translate(int x, int y) override;
	bool isPointIn(int x, int y) const override;
	double getArea() const override;
	double getPerimeter() const override;
	void print() const override;
};

