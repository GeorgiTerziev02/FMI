#pragma once
#include "Vector.hpp"
#include "Shape.h"

class ShapesCollection
{
	Vector<Shape*> shapes;

public:
	ShapesCollection() = default;
	ShapesCollection(const ShapesCollection&);
	ShapesCollection& operator=(const ShapesCollection&);
	~ShapesCollection();

	void printShapes() const;
	void createShape();
	void eraseShape();
	void translate();

private:
	void free();
	void copyFrom(const ShapesCollection&);
};

