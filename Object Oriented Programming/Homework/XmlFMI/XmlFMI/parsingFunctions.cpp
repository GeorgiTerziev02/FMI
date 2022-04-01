#include "parsingFunctions.h"
#include "stringHelperFunctions.h"
#include "helperFunctions.h"

// Check if string is a valid integer
bool isInputInteger(const char* str) {
	int length = strLength(str);
	if (length < 1) {
		return false;
	}

	int index = str[0] == '-' ? 1 : 0;

	// input is "-"
	if (index == length) {
		return false;
	}

	for (; index < length; index++) {
		if (str[index] < '0' || str[index] > '9') {
			return false;
		}
	}

	return true;
}

bool isInputDouble(const char* str) {
	int length = strLength(str);
	if (length < 1) {
		return false;
	}

	int index = str[0] == '-' ? 1 : 0;
	// first symbol is .(after dash)
	if (str[index] == '.')
	{
		return false;
	}

	// input is "-"
	if (index == length) {
		return false;
	}

	bool hasDot = false;
	for (; index < length; index++) {
		if (str[index] == '.' && hasDot) {
			return false;
		}
		else if (str[index] == '.' && !hasDot) {
			hasDot = true;
		}
		else if ((str[index] < '0' || str[index] > '9') && str[index] != '.') {
			return false;
		}
	}

	return true;
}

int intParse(char* str) {
	int stringLength = strLength(str);
	if (stringLength < 1) {
		return 0;
	}

	int index = str[0] == '-' ? 1 : 0;

	int result = 0;
	for (; index < stringLength; index++) {
		result = result * 10 + (str[index] - '0');
	}

	return str[0] == '0' ? -result : result;
}

double doubleParse(char* str) {
	int stringLength = strLength(str);
	if (stringLength < 1) {
		return 0;
	}

	int index = str[0] == '-' ? 1 : 0;

	int dotIndex = -1;
	for (size_t i = 0; i < stringLength; i++)
	{
		if (str[i] == '.')
		{
			dotIndex = i;
			break;
		}
	}

	double result = 0;
	if (dotIndex == -1)
	{
		for (size_t i = 0; i < stringLength; i++)
		{
			result = result * 10 + (str[index] - '0');
		}
	}
	else {
		for (size_t i = 0; i < dotIndex; i++)
		{
			result = result * 10 + (str[index] - '0');
		}

		// after decimal point
		for (size_t i = dotIndex + 1; i < stringLength; i++)
		{
			result += (str[i] - '0') * myPow(0.1, i - dotIndex);
		}
	}

	return str[0] == '0' ? -result : result;
}