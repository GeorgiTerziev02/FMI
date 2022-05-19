#include <iostream>
#include "Engine.h"
#include "Car.h"
#include "insufficient_fuel_error.h"

int main() {

	try
	{
		Engine engine1(1, "Honda", "Honda engine", 150);
		Tyre tyre1(2, "Bridgestone", "Summer tyres", 185, 65, 14);

		std::cout << engine1 << std::endl;
		std::cout << tyre1 << std::endl;

		Accumulator acc1(44, "test1", "test2", 44, 9);
		Tyre* tyres[4] = { &tyre1, &tyre1, &tyre1, &tyre1 };
		FuelTank fuelTank1(5000);

		Car car1(&fuelTank1, &engine1, tyres, &acc1, 1500);

		car1.drive(300);

		FuelTank fuelTank2(6000);
		Accumulator acc2(44, "test1", "test2", 44, 9);
		Engine engine2(2, "Volkswagen Group", "Engine", 140);
		Car car2(&fuelTank2, &engine2, tyres, &acc2, 4000);

		Car* winner = dragRace(&car1, &car2);

		std::cout << car1.getPower() << std::endl;
		std::cout << car2.getPower() << std::endl;

		if (winner != nullptr)
		{
			std::cout << winner->getPower() << std::endl;
		}
	}
	catch (const insufficient_fuel_error& error)
	{
		std::cout << "hello" << std::endl;
	}
}