#pragma once
#include "CarPart.h"

class Accumulator : public CarPart {
	int capacity;
	size_t batteryId;
public:
	Accumulator(size_t, const String&, const String&, int capacity, size_t batteryId);

	friend std::ostream& operator<<(std::ostream& out, const Accumulator&);
};