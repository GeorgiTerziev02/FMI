#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	point point;
	double width, height;

public: 
	Rectangle(int x, int y, double width, double height);
	Shape* clone() const override;

	void translate(int x, int y) override;
	bool isPointIn(int x, int y) const override;
	double getArea() const override;
	double getPerimeter() const override;
	void print() const override;
	const char* getTypeString() const override;

	friend std::ostream& operator<<(std::ostream&, const Rectangle&);
};

