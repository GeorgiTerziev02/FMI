#include <iostream>
#include "ShapeContainer.h"
#include "Triangle.h"
#include "Rectangle.h"

int main()
{
	ShapeContainer* test = new ShapeContainer();

	Triangle* t = new Triangle(0, 0, "white", 1, 1, 45);
	test->addShape(t);
	Rectangle* r = new Rectangle(0, 0, "red", 4, 5);
	test->addShape(r);

	test->getAreas();
	test->getInfo();

	delete test;
}