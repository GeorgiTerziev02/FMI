#include <iostream>

using namespace std;

struct Point
{
	int x, y;

	Point()
	{
		x = 0;
		y = 0;
	}

	Point(const int x, const int y)
	{
		this->x = x;
		this->y = y;
	}

	double getDistance(const Point& p) const {
		return sqrt(((this->x - p.getX()) * (this->x - p.getX()) + (this->y - p.getY()) * (this->y - p.getY())));
	}

	int getX() const {
		return x;
	}

	void setX(int x) {
		this->x = x;
	}

	int getY() const {
		return y;
	}

	void setY(int y) {
		this->y = y;
	}

};

struct Triangle {
	Point a, b, c;

	Triangle(const Point& a, const Point& b, const Point& c) {
		this->a = a;
		this->b = b;
		this->c = c;
	}

	double getPerimeter() const {
		double aSide = this->b.getDistance(this->c);
		double bSide = this->c.getDistance(this->a);
		double cSide = this->a.getDistance(this->b);

		return aSide + bSide + cSide;
	}
};


int main()
{
	Point p(1, 2);
	Point p2(2, 3);
	Point p3(4, 1);

	Triangle triangle(p, p2, p3);
	cout << triangle.getPerimeter() << endl;
}