#include "Car.h"

const double DRAG_RACE_DISTANCE = 0.4;

Car::Car(FuelTank* fuelTank, Engine* engine, Tyre* tyres[4], Accumulator* accumulator, size_t weight) {
	this->fuelTank = fuelTank;
	this->engine = engine;
	for (size_t i = 0; i < 4; i++)
		this->tyres[i] = tyres[i];

	this->accumulator = accumulator;
	this->weight = weight;
}

const FuelTank& Car::getFuelTank() const {
	return *fuelTank;
}

void Car::drive(double km) {
	fuelTank->use(km);
	drivenKm += km;
}

double Car::getPower() const {
	return weight / engine->getHP();
}

Car* dragRace(Car* car1, Car* car2) {
	if (car1->getFuelTank().getCurrent() < DRAG_RACE_DISTANCE &&
		car2->getFuelTank().getCurrent() < DRAG_RACE_DISTANCE)
		return nullptr;

	if (car1->getFuelTank().getCurrent() < DRAG_RACE_DISTANCE)
		return car2;

	if (car2->getFuelTank().getCurrent() < DRAG_RACE_DISTANCE)
		return car1;

	return car1->getPower() >= car2->getPower() ? car1 : car2;
}