#pragma once

#include <iostream>
using namespace std;

// get str length
int strLength(char* array) {
	int index = 0;
	while (array[index] != '\0') index++;

	return index;
}

// check if character is lowercase
bool isLowerCase(char a) {
	return a >= 97 && a <= 122;
}

// check if character is uppercase
bool isUpperCase(char a) {
	return a >= 65 && a <= 90;
}

// find the first space in array after particular index
// returns -1 if hits end of array
int firstSpace(char array[], int arrayLength, int afterIndex) {
	for (size_t i = afterIndex + 1; i < arrayLength; i++)
	{
		if (array[i] == ' ')
		{
			return i;
		}
	}

	return -1;
}

// find the count of lowercase and uppercase words
int* cntWords(char array[]) {
	int length = strLength(array);

	int lowerCaseWords = 0;
	int upperCaseWords = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (isUpperCase(array[i])) {
			bool allUpper = true;

			for (size_t j = i + 1; j < length; j++)
			{
				if (array[j] == ' ') break;

				if (!isUpperCase(array[j]))
				{
					allUpper = false;
					break;
				}
			}

			if (allUpper) upperCaseWords++;
		}
		else if (isLowerCase(array[i])) {
			bool allLower = true;

			for (size_t j = i + 1; j < length; j++)
			{
				if (array[j] == ' ') break;

				if (!isLowerCase(array[j]))
				{
					allLower = false;
					break;
				}
			}

			if (allLower) lowerCaseWords++;
		}

		int nextSpace = firstSpace(array, length, i);
		if (nextSpace == -1)
		{
			break;
		}
		i = nextSpace;
	}

	int* result = new int[2];
	result[0] = lowerCaseWords;
	result[1] = upperCaseWords;
	return result;
}

// find the three largest ascii codes in string and sum them
long covertNumber(char* num) {
	int length = strLength(num);

	if (length < 3)
	{
		return -1;
	}

	// sorts only the first three
	for (size_t i = 0; i < 3; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			if (num[i] < num[j]) {
				// swap
				char temp = num[i];
				num[i] = num[j];
				num[j] = temp;
			}
		}
	}

	return num[0] + num[1] + num[2];
}

// find max element, reverse array, add the max element to all other elements
void convertMax(int* array, int N) {
	int max = INT_MIN;

	// find max
	for (size_t i = 0; i < N; i++)
	{
		if (max < array[i]) max = array[i];
	}

	// reverse
	for (size_t i = 0; i < (N / 2); i++)
	{
		int temp = array[i];
		array[i] = array[N - i - 1];
		array[N - i - 1] = temp;
	}

	// add
	for (size_t i = 0; i < N; i++)
	{
		if (array[i] != max)
		{
			array[i] += max;
		}
	}

}

// print array elements
void printArray(int* array, int N) {
	for (size_t i = 0; i < N; i++)
	{
		cout << array[i] << " ";
	}

	cout << endl;
}

// check if char array can be converted to palindromel
int checkStr(char array[]) {
	if (array == NULL)
	{
		return -1;
	}

	int length = strLength(array);
	if (length < 2)
	{
		return -1;
	}

	int asciiArray[256];
	for (size_t i = 0; i < 256; i++)
	{
		asciiArray[i] = 0;
	}

	// will be used as length later
	int index = 0;
	while (array[index] != '\0')
	{
		asciiArray[array[index++]]++;
	}

	if (length % 2 == 0)
	{
		for (size_t i = 0; i < 256; i++)
		{
			if (asciiArray[i] % 2 != 0)
			{
				return 0;
			}
		}
	}
	else {
		// you can have only one odd
		int oddCount = 0;
		for (size_t i = 0; i < 256; i++)
		{
			if (asciiArray[i] % 2 != 0)
			{
				oddCount++;
				if (oddCount > 1)
				{
					return 0;
				}
			}
		}
	}

	return 1;
}