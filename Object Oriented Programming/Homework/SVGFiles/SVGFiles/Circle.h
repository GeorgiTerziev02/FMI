#pragma once
#include "Shape.h"

class Circle : public Shape
{
	point center;
	double radius;
public:
	Circle(int x, int y, double radius);

	Shape* clone() const override;

	void translate(int x, int y) override;
	bool isPointIn(int x, int y) const override;
	double getArea() const override;
	double getPerimeter() const override;
	void print() const override;
	const char* getTypeString() const override;

	friend std::ostream& operator<<(std::ostream& out, const Circle&);
};

