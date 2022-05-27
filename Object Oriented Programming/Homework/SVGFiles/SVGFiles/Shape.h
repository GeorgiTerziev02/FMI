#pragma once
class Shape
{
protected:
	struct point
	{
		int x, y;
		point(int x = 0, int y = 0)
			: x(x), y(y) {}
	}point;
public:
	virtual Shape* clone() const = 0;

	void translate(int x, int y);

	virtual bool isPointIn(int x, int y) const = 0;
	virtual double getArea() const = 0;
	virtual double getPerimeter() const = 0;
	virtual void print() const = 0;
};

