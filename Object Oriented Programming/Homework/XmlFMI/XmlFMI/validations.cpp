#include "validations.h"
#include "constants.h"
#include "system.h"
#include "stringHelperFunctions.h"
#include "helperFunctions.h"

bool isNameValid(const char* name) {
	return strLength(name) <= FIELD_MAX_SIZE;
}

bool isFnValid(const System& system, const int& fn) {
	return getStudentIndexByFn(system, fn) == -1;
}

bool isAgeValid(const int& age) {
	return MIN_AGE <= age && age <= MAX_AGE;
}

bool isGenderValid(const char* gender) {
	return strCmp(gender, MALE) == 0 || strCmp(gender, FEMALE) == 0;
}

bool isEmailValid(const char* email) {
	if (strLength(email) > FIELD_MAX_SIZE)
	{
		return false;
	}

	int index = 0;
	while (email[index] != '\0')
	{
		if (email[index++] == '@')
		{
			return true;
		}
	}

	return false;
}

bool isGradeValid(const double& grade) {
	return MIN_GRADE <= grade && grade <= MAX_GRADE;
}
