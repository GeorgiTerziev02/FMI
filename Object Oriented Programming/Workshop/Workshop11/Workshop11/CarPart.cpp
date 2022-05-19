#include "CarPart.h"
#include "String.h"
#include <iostream>

CarPart::CarPart(size_t id, const String& manufacturer, const String& description) {
	this->id = id;
	this->manufacturer = manufacturer;
	this->description = description;
}

std::ostream& operator<<(std::ostream& out, const CarPart& carPart) {
	out << carPart.id << " by " << carPart.manufacturer << " - " << carPart.description;

	return out;
}