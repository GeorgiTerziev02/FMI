#pragma once
#include "Shape.h"
class Line : public Shape
{
	point p1, p2;

public:
	Line(int x1, int y1, int x2, int y2, const String& stroke, int strokeWidth);
	Shape* clone() const override;

	void translate(int x, int y) override;
	bool isPointIn(int x, int y) const override;
	bool isWithin(const Shape*) const override;
	double getArea() const override;
	double getPerimeter() const override;
	void print() const override;
	const char* getTypeString() const override;

	friend std::ostream& operator<<(std::ostream&, const Line&);
};

