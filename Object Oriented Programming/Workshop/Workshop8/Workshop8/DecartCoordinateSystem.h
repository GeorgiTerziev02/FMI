#pragma once
#include "Nvector.h"

class DecartCoordinateSystem
{
private:
	Nvector v1, v2;
public:
	DecartCoordinateSystem(const Nvector& v1, const Nvector& v2);

	Nvector getVectorByCoordinates(int c1, int c2) const;
	Nvector getCoordinatesByVector(int c1, int c2) const;
};

