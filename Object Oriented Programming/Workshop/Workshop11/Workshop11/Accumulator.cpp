#include "Accumulator.h"

Accumulator::Accumulator(size_t id, const String& manufacturer, const String& description, int capacity, size_t batteryId)
	: CarPart(id, manufacturer, description), capacity(capacity), batteryId(batteryId) {}

std::ostream& operator<<(std::ostream& out, const Accumulator& accumulator) {
	out << (CarPart&)accumulator << " - " << accumulator.capacity << " Ah";

	return out;
}