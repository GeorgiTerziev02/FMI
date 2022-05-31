#pragma once
#include <iostream>
#include "String.h"

class Shape
{
protected:
	struct point
	{
		int x, y;
		point(int x = 0, int y = 0)
			: x(x), y(y) {}

		double getDist(const point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}

		void translate(int x, int y) {
			this->x += x;
			this->y += y;
		}
	};

	enum TypeOfShape
	{
		Rectangle,
		Circle,
		Line
	} type;

	String stroke;
	int strokeWidth;
public:
	Shape(const String& stroke, int strokeWidth);
	virtual ~Shape() {};
	virtual Shape* clone() const = 0;

	virtual void translate(int x, int y) = 0;
	virtual bool isPointIn(int x, int y) const = 0;
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void print() const = 0;
	virtual const char* getTypeString() const = 0;
};

