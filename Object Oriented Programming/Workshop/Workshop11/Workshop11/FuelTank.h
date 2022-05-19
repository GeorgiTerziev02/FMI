#pragma once
class FuelTank
{
	double capacity;
	double current;
public:
	FuelTank(double capacity);

	double getCurrent() const;

	void use(double toUse);
	void fill(double toFill);
};

