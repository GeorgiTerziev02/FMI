#include "FuelTank.h"
#include "insufficient_fuel_error.h"

FuelTank::FuelTank(double capacity) {
	this->capacity = capacity;
	this->current = capacity;
}

double FuelTank::getCurrent() const {
	return current;
}

void FuelTank::use(double toUse) {
	if (current < toUse)
		throw insufficient_fuel_error("Not enough fuel!");

	current -= toUse;
}

void FuelTank::fill(double toFill) {
	current += toFill;
	if (current > capacity)
		current = capacity;
}