#include "ShapeContainer.h"

void ShapeContainer::free() {
	for (size_t i = 0; i < shapes.getSize(); i++)
		delete shapes[i];
}

ShapeContainer::~ShapeContainer() {
	free();
}

void ShapeContainer::addShape(Shape* shape) {
	shapes.pushBack(shape);
}

void ShapeContainer::getInfo() const {
	for (size_t i = 0; i < shapes.getSize(); i++)
		shapes[i]->getInfo();
}

void ShapeContainer::getAreas() const {
	for (size_t i = 0; i < shapes.getSize(); i++)
		std::cout << shapes[i]->getArea() << std::endl;
}