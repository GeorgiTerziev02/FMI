#include "Tyre.h"

Tyre::Tyre(size_t id, const String& manufacturer, const String& description, short width, short profile, short diameter)
	: CarPart(id, manufacturer, description), width(width), profile(profile), diameter(diameter) {}

std::ostream& operator<<(std::ostream& out, const Tyre& tyre) {
	out << (CarPart&)tyre << " - " << tyre.width << "/" << tyre.profile << "R" << tyre.diameter;

	return out;
}