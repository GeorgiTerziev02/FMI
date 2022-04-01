#include "stringHelperFunctions.h"

using namespace std;

void my_strcpy(char* dest, const char* source)
{
	size_t index = 0;
	while (source[index] != '\0')
	{
		dest[index] = source[index];
		index++;
	}
	dest[index] = '\0';
}

int strLength(const char* str) {
	int size = 0;
	while (str[size] != '\0') { size++; }

	return size;
}

int strCmp(const char* str1, const char* str2) {
	int length1 = strLength(str1);
	int length2 = strLength(str2);
	int smallerLength = length1 < length2 ? length1 : length2;

	for (size_t i = 0; i < smallerLength; i++)
	{
		if (str1[i] - str2[i] != 0) return str1[i] - str2[i];
	}

	return length1 - length2;
}

int indexOf(const char* str1, const int& fromIndex, const char& character) {
	int index = fromIndex;

	while (str1[index] != '\0')
	{
		if (str1[index] == character)
		{
			return index;
		}
		index++;
	}

	return -1;
}

char* subStr(const char* str, const int& startIndex, const int& endIndex) {
	int resultSize = endIndex - startIndex + 2;
	char* result = new char[resultSize];

	int length = strLength(str);
	if (startIndex > endIndex || endIndex >= length)
	{
		return result;
	}

	for (size_t i = 0; i < resultSize - 1; i++)
	{
		result[i] = str[startIndex + i];
	}

	result[resultSize - 1] = '\0';

	return result;
}