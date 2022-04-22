#include "Grade.h"
#include <cstring>

#pragma warning(disable : 4996)

Grade::Grade() {
	grade = 0;
	task = new char[1];
	task[0] = '\0';

	from = new char[1];
	from[0] = '\0';
}

Grade::Grade(const double grade, const char* task, const char* from) {
	this->grade = grade;

	this->task = new char[strlen(task) + 1];
	strcpy(this->task, task);

	this->from = new char[strlen(from) + 1];
	strcpy(this->from, from);
}

Grade::Grade(const Grade& other) {
	copy(other);
}

Grade& Grade::operator=(const Grade& other) {
	if (this != &other) {
		free();
		copy(other);
	}

	return *this;
}

Grade::~Grade() {
	free();
}

void Grade::copy(const Grade& other) {
	grade = other.grade;

	task = new char[strlen(other.task) + 1];
	strcpy(task, other.task);

	from = new char[strlen(other.from) + 1];
	strcpy(from, other.from);
}

void Grade::free() {
	delete[] task;
	delete[] from;
}

double Grade::getGrade() const {
	return grade;
}

const char* Grade::getTask() const {
	return task;
}

const char* Grade::getFrom() const {
	return from;
}

void Grade::setGrade(const double grade) {
	this->grade = grade;
}