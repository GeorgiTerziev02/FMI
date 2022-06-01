#pragma once
#include "Shape.h"
class Rectangle : public Shape
{
	point point;
	double width, height;
	String fill;
public: 
	Rectangle(int x, int y, double width, double height, const String& fill, const String& stroke, int strokeWidth);
	Shape* clone() const override;

	void translate(int x, int y) override;
	bool isPointIn(int x, int y) const override;
	bool isWithin(const Shape*) const override;
	double getArea() const override;
	double getPerimeter() const override;
	void print() const override;
	const char* getTypeString() const override;

	friend std::ostream& operator<<(std::ostream&, const Rectangle&);
};

