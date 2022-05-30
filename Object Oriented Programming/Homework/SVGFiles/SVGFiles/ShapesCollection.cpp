#include "ShapesCollection.h"

ShapesCollection::ShapesCollection(const ShapesCollection& other) {
	copyFrom(other);
}

ShapesCollection& ShapesCollection::operator=(const ShapesCollection& other) {
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

ShapesCollection::~ShapesCollection() {
	free();
}

void ShapesCollection::free() {
	for (size_t i = 0; i < shapes.getSize(); i++)
		delete shapes[i];

	shapes.clear();
}

void ShapesCollection::copyFrom(const ShapesCollection& other) {
	for (size_t i = 0; i < shapes.getSize(); i++)
		shapes.pushBack(other.shapes[i]->clone());
}

const Vector<Shape*>& ShapesCollection::getShapes() const {
	return shapes;
}

void ShapesCollection::printShapes() const {
	for (size_t i = 0; i < shapes.getSize(); i++)
		shapes[i]->print();
}

void ShapesCollection::addShape(const Shape* shape) {
	shapes.pushBack(shape->clone());
}

//void ShapesCollection::createShape();
void ShapesCollection::eraseShape(size_t index) {
	if (index >= shapes.getSize())
		throw "Invalid index";

	shapes.popAt(index);
}

void ShapesCollection::translate(int x, int y, int index = -1) {
	if (index == -1)
	{
		for (size_t i = 0; i < shapes.getSize(); i++)
			shapes[i]->translate(x, y);

		return;
	}

	if (index < 0 || index >= shapes.getSize())
		throw "Invalid index";

	shapes[index]->translate(x, y);
}