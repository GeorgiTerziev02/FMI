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
	size_t size = shapes.getSize();
	for (size_t i = 0; i < size; i++)
		delete shapes[i];

	shapes.clear();
}

void ShapesCollection::copyFrom(const ShapesCollection& other) {
	size_t size = other.shapes.getSize();

	for (size_t i = 0; i < size; i++)
		shapes.pushBack(other.shapes[i]->clone());
}

void ShapesCollection::printShapes() const {
	size_t size = shapes.getSize();
	for (size_t i = 0; i < size; i++)
		shapes[i]->print();
}

void ShapesCollection::addShape(const Shape* shape) {
	shapes.pushBack(shape->clone());
}

//void ShapesCollection::createShape();
//void ShapesCollection::eraseShape();
//void ShapesCollection::translate();