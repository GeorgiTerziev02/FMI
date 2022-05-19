#pragma once

#include "FuelTank.h"
#include "Engine.h"
#include "Tyre.h"
#include "Accumulator.h"

class Car
{
	FuelTank* fuelTank;
	Engine* engine;
	Tyre* tyres[4];
	Accumulator* accumulator;
	size_t drivenKm;
	size_t weight;
public:
	Car(FuelTank*, Engine*, Tyre* tyres[4], Accumulator*, size_t);

	const FuelTank& getFuelTank() const;
	void drive(double km);
	double getPower() const;

	friend Car* dragRace(Car* car1, Car* car2);
};

