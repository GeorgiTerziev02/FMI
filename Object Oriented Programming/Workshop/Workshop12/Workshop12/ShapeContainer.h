#pragma once
#include "Shape.h"
#include "Vector.hpp"

class ShapeContainer
{
	Vector<Shape*> shapes;
 
	void free();
	//void copyFrom(const ShapeContainer&);
public:
	//ShapeContainer();
	ShapeContainer(const ShapeContainer&) = delete;
	ShapeContainer& operator=(const ShapeContainer&) = delete;
	~ShapeContainer();

	void addShape(Shape*);
	void getInfo() const;
	void getAreas() const;
};

