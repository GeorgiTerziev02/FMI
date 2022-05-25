#pragma once
#include <iostream>
#include "String.h"

class Shape
{
protected:
	struct point
	{
		point() :x(0), y(0) {}
		point(int x, int y) :x(x), y(y) {}
		int x;
		int y;
		double getDist(const point& other) const
		{
			int dx = x - other.x;
			int dy = y - other.y;

			return sqrt(dx * dx + dy * dy);
		}
	};

	point point;
	String color;

public:
	Shape(int x, int y, const String& color);
	virtual ~Shape() {}

	virtual double getArea() const = 0;
	virtual void getInfo() const = 0;
};

