#include "Assistant.h"
#include <cstring>

#pragma warning(disable : 4996)

Assistant::Assistant()
{
	name = new char[1];
	name[0] = '\0';
}
Assistant::Assistant(const char* name) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

Assistant::Assistant(const Assistant& other) {
	copy(other);
}

Assistant& Assistant::operator=(const Assistant& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Assistant::~Assistant() {
	free();
}

void Assistant::copy(const Assistant& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
}

void Assistant::free() {
	delete[] name;
}

const char* Assistant::getName() const {
	return name;
}