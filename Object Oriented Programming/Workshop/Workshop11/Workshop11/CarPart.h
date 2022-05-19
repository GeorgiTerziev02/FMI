#pragma once
#include "CarPart.h"
#include "String.h"
#include <iostream>

class CarPart
{
	size_t id;
	String manufacturer;
	String description;
public:
	CarPart(size_t, const String&, const String&);

	friend std::ostream& operator<<(std::ostream&, const CarPart&);
};

