#pragma once
#include "CarPart.h"

class Tyre : public CarPart {
	short width;
	short profile;
	short diameter;
public:
	Tyre(size_t, const String&, const String&, short width, short profile, short diameter);

	friend std::ostream& operator<<(std::ostream& out, const Tyre&);
};