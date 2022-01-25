#pragma once

#include <iostream>

using namespace std;

// input
// 1 2 3 4 5 6 7 8
// result should be
// 1 8 7 6 5 4 3 2
void convertArray(int array[], int startIndex, int endIndex) {
	int end = (endIndex - startIndex + 1) / 2;

	for (size_t i = 0; i < end; i++)
	{
		int temp = array[startIndex + i];
		array[startIndex + i] = array[endIndex - i];
		array[endIndex - i] = temp;
	}
}

int numberLength(int n) {
	int length = 0;

	while (n != 0) {
		length++;
		n /= 10;
	}

	return length;
}

int getEncodedLength(const char* const array) {
	int index = 0;
	int length = 0;

	while (array[index] != '\0') {
		// + ascii length + 1 for underscore
		length += numberLength(array[index]) + 1;
		index++;
	}

	return length;
}

// input
// abc
// result should be
// 97_98_99 (ascii codes of the chars)
char* Encode(char* array) {
	int resultLength = getEncodedLength(array);

	// we will use the extra 1 length for '\0'
	char* result = new char[resultLength];

	int index = 0;
	int resultArrayIndex = 0;
	while (array[index] != '\0') {
		int asciiCode = array[index];
		int numberLengthOfAsciiCode = numberLength(asciiCode);
		resultArrayIndex += numberLengthOfAsciiCode - 1;
		while (asciiCode != 0)
		{
			result[resultArrayIndex] = (asciiCode % 10) + '0';
			resultArrayIndex--;
			asciiCode /= 10;
		}
		resultArrayIndex += numberLengthOfAsciiCode + 1;
		if (resultArrayIndex < resultLength)
		{
			result[resultArrayIndex] = '_';
			resultArrayIndex++;
		}
		index++;
	}

	result[resultLength - 1] = '\0';
	return result;
}

double fact(double n) {
	if (n == 0)
	{
		return 1;
	}

	return fact(n - 1) * n;
}

double myAbs(double n) {
	return n > 0 ? n : -n;
}

double myPow(double n, int degree) {
	double result = 1;
	for (size_t i = 0; i < degree; i++)
	{
		result *= n;
	}

	return result;
}

double mySin(double degrees, double eps) {
	double result = 0;
	double x = (degrees / 180) * 3.14;
	double current = x;

	int index = 0;
	while (myAbs(current) > eps) {
		current = (myPow(-1, index) * myPow(x, 2 * index + 1)) / fact((2 * index) + 1);
		result += current;

		index++;
	}

	return result;
}

double myCos(double degrees, double eps) {
	double result = 0;
	double x = (degrees / 180) * 3.14;
	double current = 500;

	int index = 0;
	while (myAbs(current) > eps) {
		current = (myPow(-1, index) * myPow(x, 2 * index)) / fact(2 * index);
		result += current;

		index++;
	}

	return result;
}

double mySqrt(double n, double eps) {
	double x = n;

	while (myAbs(n - x * x) > eps) {
		x = (x + n / x) / 2;
	}

	return x;
}

// e^x
double myExponential(double n, double eps) {
	double current = 1;
	double result = 1;
	int index = 1;

	while (myAbs(current) > eps)
	{
		current = myPow(n, index) / fact(index);
		result += current;
		index++;
	}

	return result;
}
