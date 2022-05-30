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
	void createShape(const Shape* shape);
	void eraseShape(size_t index);
	void translate(int x, int y, int index = -1);
	const Vector<Shape*>& getShapes() const;

private:
	void free();
	void copyFrom(const ShapesCollection&);
};

