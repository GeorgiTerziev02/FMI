#include "stringHelperFunctions.h"
#include <cstring>

int indexOf(const char* str1, const int& fromIndex, const char& character) {
	int index = fromIndex;

	while (str1[index] != '\0')
	{
		if (str1[index] == character)
			return index;

		index++;
	}

	return -1;
}

char* subStr(const char* str, const int& startIndex, const int& endIndex) {
	int resultSize = endIndex - startIndex + 2;
	char* result = new char[resultSize];

	int length = strlen(str);
	if (startIndex > endIndex || endIndex >= length)
		return result;

	for (size_t i = 0; i < resultSize - 1; i++)
		result[i] = str[startIndex + i];

	result[resultSize - 1] = '\0';

	return result;
}

Vector<char*> split(const char* str, char separator) {
	size_t length = strlen(str);

	size_t currentIndex = 0;
	Vector<char*> result;
	while (currentIndex < length)
	{
		// we found first symbol
		if (str[currentIndex] != separator)
		{
			size_t indexOfFirstSpace = indexOf(str, currentIndex, separator);
			char* partial = subStr(str, currentIndex + 1, indexOfFirstSpace - 1);
			currentIndex = indexOfFirstSpace;
			result.pushBack(partial);
		}

		currentIndex++;
	}

	return result;
}