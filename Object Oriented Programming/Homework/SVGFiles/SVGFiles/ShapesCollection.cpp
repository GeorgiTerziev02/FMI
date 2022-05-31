#include "ShapesCollection.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

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

void ShapesCollection::createShape(const Shape* shape) {
	shapes.pushBack(shape->clone());
}

void ShapesCollection::eraseShape(size_t index) {
	if (index >= shapes.getSize())
		throw "Invalid index";

	shapes.popAt(index);
}

void ShapesCollection::translate(int x, int y, int index) {
	if (index == -1) {
		for (size_t i = 0; i < shapes.getSize(); i++)
			shapes[i]->translate(x, y);

		return;
	}

	if (index < 0 || index >= shapes.getSize())
		throw "Invalid index";

	shapes[index]->translate(x, y);
}

void ShapesCollection::printContainingPoint(int x, int y) const {
	for (size_t i = 0; i < shapes.getSize(); i++)
		if (shapes[i]->isPointIn(x, y))
			shapes[i]->print();
}

void ShapesCollection::printShapes() const {
	for (size_t i = 0; i < shapes.getSize(); i++) {
		std::cout << i + 1 << ". ";
		shapes[i]->print();
	}
}
void ShapesCollection::printPerimeters() const {
	for (size_t i = 0; i < shapes.getSize(); i++)
		std::cout << i + 1 << " " << shapes[i]->getTypeString() << " " << shapes[i]->getPerimeter();
}

void ShapesCollection::printAreas() const {
	for (size_t i = 0; i < shapes.getSize(); i++)
		std::cout << i + 1 << " " << shapes[i]->getTypeString() << " " << shapes[i]->getArea();
}

std::ostream& operator<<(std::ostream& out, const ShapesCollection& collection) {
	out << "<svg xmlns=\"http://www.w3.org/2000/svg\" version=\"1.1\">" << std::endl;
	for (size_t i = 0; i < collection.shapes.getSize(); i++) {
		if (strcmp(collection.shapes[i]->getTypeString(), "Circle") == 0)
			out << '\t' << *((Circle*)collection.shapes[i]) << std::endl;
		else if (strcmp(collection.shapes[i]->getTypeString(), "Rectangle") == 0)
			out << '\t' << *((Rectangle*)collection.shapes[i]) << std::endl;
		else if (strcmp(collection.shapes[i]->getTypeString(), "Line") == 0)
			out << '\t' << *((Line*)collection.shapes[i]) << std::endl;
	}
	out << "</svg>" << std::endl;

	return out;
}