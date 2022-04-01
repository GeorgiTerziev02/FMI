#include "helperFunctions.h"
#include "constants.h"
#include <iostream>
#include "stringHelperFunctions.h"

using namespace std;

void printInputCharacter() {
	cout << ">";
}

void printOperationResultMessage(bool result) {
	cout << (result ? SUCCESSFUL_OPERATION_MESSAGE : UNSUCCESSFUL_OPERATION_MESSAGE) << endl;
}

void printDataErrorMessage() {
	cout << VALIDATION_ERROR_MESSAGE << endl;
}

double myPow(double number, int degree) {
	int index = 1;
	double result = 1;

	while (index++ <= degree)
	{
		result *= number;
	}

	return result;
}

bool checkRequiredFields(bool validationArray[FIELDS_COUNT]) {
	for (size_t i = 0; i < FIELDS_COUNT; i++)
	{
		if (!validationArray[i])
		{
			return false;
		}
	}

	return true;
}

char* getTag(const char* buffer, int& startIndex) {
	int indexOfLeftArrowOfOpeningTag = indexOf(buffer, startIndex, '<');
	int indexOfRightArrowOfOpeningTag = indexOf(buffer, indexOfLeftArrowOfOpeningTag, '>');
	startIndex = indexOfRightArrowOfOpeningTag;
	return subStr(buffer, indexOfLeftArrowOfOpeningTag + 1, indexOfRightArrowOfOpeningTag - 1);
}

int getStudentIndexByFn(const System& system, const int& fn) {
	for (size_t i = 0; i < system.size; i++)
	{
		if (system.students[i].fn == fn)
		{
			return i;
		}
	}

	return -1;
}

void printStudent(const Student& student) {
	cout << NAME_TAG << ": " << student.name << endl;
	cout << FN_TAG << ": " << student.fn << endl;
	cout << AGE_TAG << ": " << student.age << endl;
	cout << GENDER_TAG << ": " << (student.gender ? MALE : FEMALE) << endl;
	cout << EMAIL_TAG << ": " << student.email << endl;
	cout << GRADE_TAG << ": " << student.grade << endl;
	cout << endl;
}