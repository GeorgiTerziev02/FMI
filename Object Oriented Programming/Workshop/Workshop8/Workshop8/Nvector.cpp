#include "Nvector.h"
#include <iostream>

Nvector::Nvector() {
	size = 0;
	coordinates = nullptr;
}
Nvector::Nvector(int size) {
	this->size = size;
	coordinates = new int[size]();
}

Nvector::Nvector(const Nvector& other) {
	copy(other);
}

Nvector& Nvector::operator=(const Nvector& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Nvector::~Nvector() {
	free();
}


void Nvector::free() {
	delete[] coordinates;
}

void Nvector::copy(const Nvector& other) {
	size = other.size;
	coordinates = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		coordinates[i] = other.coordinates[i];
	}
}

Nvector& Nvector::operator+=(const Nvector& other) {
	if (size != other.size) {
		throw "Different sizes";
	}

	for (size_t i = 0; i < size; i++)
	{
		coordinates[i] += other.coordinates[i];
	}

	return *this;
}

Nvector& Nvector::operator-=(const Nvector& other) {
	if (size != other.size) {
		throw "Different sizes";
	}

	for (size_t i = 0; i < size; i++)
	{
		coordinates[i] -= other.coordinates[i];
	}

	return *this;
}

Nvector& Nvector::operator*=(const int number) {
	if (size != 0) {
		throw "Incorrect sizes";
	}

	for (size_t i = 0; i < size; i++)
	{
		coordinates[i] *= number;
	}

	return *this;
}

int& Nvector::operator[](int index) {
	return coordinates[index];
}

int Nvector::operator[](int index) const {
	return coordinates[index];
}

bool Nvector::isPerpendicular(const Nvector& other) const {
	if (size != other.size) return false;

	int result = 0;
	for (size_t i = 0; i < size; i++)
	{
		result += coordinates[i] * other.coordinates[i];
	}

	return result == 0;
}

double Nvector::getLength() const {
	double result = 0;

	for (size_t i = 0; i < size; i++)
	{
		result += coordinates[i] * coordinates[i];
	}

	return sqrt(result);
}

Nvector operator+(const Nvector& v1, const Nvector& v2) {
	Nvector temp(v1);
	temp += v2;

	return temp;
}

Nvector operator-(const Nvector& v1, const Nvector& v2) {
	Nvector temp(v1);
	temp -= v2;

	return temp;
}

Nvector operator*(const Nvector& v1, const int number) {
	Nvector temp(v1);
	temp *= number;

	return temp;
}

std::istream& operator>>(std::istream& in, Nvector& nvector) {
	for (size_t i = 0; i < nvector.size; i++)
	{
		in >> nvector.coordinates[i];
	}

	return in;
}

std::ostream& operator<<(std::ostream& out, const Nvector& nvector) {
	for (size_t i = 0; i < nvector.size; i++)
	{
		out << nvector.coordinates[i] << " ";
	}

	return out;
}