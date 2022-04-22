#include "Student.h"
#include <cstring>

#pragma warning(disable : 4996)

Student::Student()
{
	name = new char[1];
	name[0] = '\0';
}

Student::Student(const char* name, const int fn) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->fn = fn;
}

Student::Student(const Student& other) {
	copy(other);
}

Student& Student::operator=(const Student& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Student::~Student() {
	free();
}

void Student::copy(const Student& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	fn = other.fn;

	for (size_t i = 0; i < MAX_GRADES_SIZE; i++)
	{
		grades[i] = other.grades[i];
	}
}

void Student::free() {
	delete[] name;
}

int Student::getFn() const {
	return fn;
}

const char* Student::getName() const {
	return name;
}

const Grade* Student::getGrades() const {
	return grades;
}

short Student::getGradesCount() const {
	return gradesCount;
}

bool Student::addGrade(const Grade& grade) {
	if (gradesCount >= MAX_GRADES_SIZE) return false;

	for (size_t i = 0; i < gradesCount; i++)
	{
		if (strcmp(grades[i].getTask(), grade.getTask()) == 0)
		{
			return false;
		}
	}

	grades[gradesCount++] = grade;
	return true;
}

bool Student::editGrade(const Grade& grade) {
	int gradeIndex = -1;
	for (size_t i = 0; i < gradesCount; i++)
	{
		if (strcmp(grades[i].getTask(), grade.getTask()) == 0)
		{
			gradeIndex = i;
			break;
		}
	}

	if (gradeIndex == -1) return false;

	grades[gradeIndex].setGrade(grade.getGrade());
	return true;
}