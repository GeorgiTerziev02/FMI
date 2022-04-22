#include "Lectorer.h"
#include <cstring>

#pragma warning(disable : 4996)

Lectorer::Lectorer()
{
	name = new char[1];
	name[0] = '\0';
}

Lectorer::Lectorer(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Lectorer::Lectorer(const Lectorer& other) {
	copy(other);
}

Lectorer& Lectorer::operator=(const Lectorer& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Lectorer::~Lectorer() {
	free();
}

void Lectorer::copy(const Lectorer& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void Lectorer::free() {
	delete[] name;
}

const char* Lectorer::getName() const {
	return name;
}