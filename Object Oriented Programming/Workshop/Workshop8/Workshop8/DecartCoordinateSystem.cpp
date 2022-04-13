#include "DecartCoordinateSystem.h"

DecartCoordinateSystem::DecartCoordinateSystem(const Nvector& v1, const Nvector& v2) {
	this->v1 = v1;
	this->v2 = v2;
}

Nvector DecartCoordinateSystem::getVectorByCoordinates(int c1, int c2) const {
	Nvector result(2);
	result[0] = c1 * v1[0] + c2 * v2[0];
	result[1] = c1 * v1[1] + c2 * v2[1];

	return result;
}

Nvector DecartCoordinateSystem::getCoordinatesByVector(int c1, int c2) const {
	Nvector result(2);

	int det = v1[0] * v2[1] - v1[1] * v2[0];

	double x1 = (v2[1] * c1 - v2[0] * c2) / det;
	double x2 = (v1[0] * c2 - v1[1] * c1) / det;

	result[0] = (int)x1;
	result[1] = (int)x2;

	return result;
}