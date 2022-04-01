#include "commands.h"
#include "stringHelperFunctions.h"
#include "validations.h"
#include "helperFunctions.h"
#include "parsingFunctions.h"

void printStudents(const System& system) {
	for (size_t i = 0; i < system.size; i++)
	{
		printStudent(system.students[i]);
	}
}

bool editValue(System& system, const char* inputData) {
	int index = indexOf(inputData, 0, ' ');
	char* fnString = subStr(inputData, 0, index - 1);
	int fn = intParse(fnString);
	delete[] fnString;

	int studentIndex = getStudentIndexByFn(system, fn);
	if (studentIndex == -1)
	{
		return false;
	}

	int endIndexOfProperty = indexOf(inputData, index + 1, ' ');
	char* property = subStr(inputData, index + 1, endIndexOfProperty - 1);

	int inputDataLength = strLength(inputData);
	char* newValue = subStr(inputData, endIndexOfProperty + 1, inputDataLength - 1);

	bool result = false;
	if (strCmp(property, NAME_TAG) == 0)
	{
		if (isNameValid(newValue))
		{
			my_strcpy(system.students[studentIndex].name, newValue);
			result = true;
		}
	}
	else if (strCmp(property, FN_TAG) == 0) {
		if (isInputInteger(newValue))
		{
			int newFn = intParse(newValue);
			if (isFnValid(system, fn))
			{
				system.students[studentIndex].fn = newFn;
				result = true;
			}
		}
	}
	else if (strCmp(property, AGE_TAG) == 0) {
		if (isInputInteger(newValue))
		{
			int newAge = intParse(newValue);
			if (isAgeValid(newAge))
			{
				system.students[studentIndex].age = newAge;
				result = true;
			}
		}
	}
	else if (strCmp(property, GENDER_TAG) == 0) {
		if (isGenderValid(newValue))
		{
			bool newGender = strCmp(newValue, MALE) == 0;
			system.students[studentIndex].gender = newGender;
			result = true;
		}
	}
	else if (strCmp(property, EMAIL_TAG) == 0) {
		if (isEmailValid(newValue))
		{
			my_strcpy(system.students[studentIndex].email, newValue);
			result = true;
		}
	}
	else if (strCmp(property, GRADE_TAG) == 0) {
		if (isInputDouble(newValue))
		{
			double doubleValue = doubleParse(newValue);
			if (isGradeValid(doubleValue))
			{
				system.students[studentIndex].grade = doubleValue;
				result = true;
			}
		}
	}

	delete[] newValue;
	delete[] property;

	return result;
}

void swapStudents(Student& firstStudent, Student& secondStudent) {
	Student temp = firstStudent;
	firstStudent = secondStudent;
	secondStudent = temp;
}

void sortBy(System& system, const char* sortingProperty) {
	if (strCmp(sortingProperty, NAME_TAG) == 0)
	{
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (strCmp(system.students[i].name, system.students[j].name) > 0)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, FN_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].fn > system.students[j].fn)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, AGE_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].age > system.students[j].age)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, GENDER_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].gender > system.students[j].gender)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, EMAIL_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (strCmp(system.students[i].email, system.students[j].email) > 0)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
	else if (strCmp(sortingProperty, GRADE_TAG) == 0) {
		for (size_t i = 0; i < system.size - 1; i++)
		{
			for (size_t j = i + 1; j < system.size; j++)
			{
				if (system.students[i].grade > system.students[j].grade)
				{
					swapStudents(system.students[i], system.students[j]);
				}
			}
		}
	}
}
