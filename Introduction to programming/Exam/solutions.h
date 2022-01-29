#pragma once

int evenCount(int num) {
	int length = 0;

	while (num != 0)
	{
		if ((num % 10) % 2 == 0)
		{
			length++;
		}
		num /= 10;
	}

	return length;
}

// task 1
long newNum(long num) {
	int length = evenCount(num);
	int* newNumArray = new int[length];
	for (size_t i = 0; i < length; i++)
	{
		newNumArray[i] = 0;
	}

	int index = 1;
	while (num != 0)
	{
		if ((num % 10) % 2 == 0)
		{
			newNumArray[length - index] = num % 10;
			index++;
		}

		num /= 10;
	}

	long result = 0;
	for (size_t i = 0; i < length; i++)
	{
		result = result * 10 + newNumArray[i];
	}

	delete[] newNumArray;
	return result;
}

// task 2
int* mergeArr(int* arr1, int* arr2, int len) {
	int* result = new int[len];

	for (size_t i = 0; i < len; i++)
	{
		int current = arr1[i];

		bool foundLarger = false;
		for (size_t j = 0; j < len; j++)
		{
			if (arr2[j] > current)
			{
				foundLarger = true;
				result[i] = j;
				break;
			}
		}

		if (!foundLarger)
		{
			result[i] = -1;
		}
	}

	return result;
}

int myStrLength(char* str) {
	int index = 0;
	while (str[index] != '\0') index++;

	return index;
}

bool isWhitespace(char c) {
	return c == ' ' || c == '\t';
}

char convertChar(char c) {
	if (c >= 65 && c <= 90)
	{
		c = c + 32;
	}
	else if (c >= 97 && c <= 122) {
		c = c - 32;
	}

	return c;
}

// task 3
char* getWord(char* str, int k) {
	int length = myStrLength(str);
	int wordsCount = 0;

	for (size_t i = 0; i < length; i++)
	{
		if (!isWhitespace(str[i]))
		{
			int currentStartIndex = i;
			wordsCount++;
			for (size_t j = i + 1; j < length; j++)
			{
				i = j;
				if (isWhitespace(str[j]))
				{
					break;
				}
			}

			if (wordsCount > k)
			{
				break;
			}

			if (wordsCount == k)
			{
				int wordLength = i - currentStartIndex + 1;
				char* result = new char[wordLength + 1];

				for (size_t j = 0; j < wordLength; j++)
				{
					result[j] = convertChar(str[currentStartIndex + j]);
				}

				result[wordLength] = '\0';

				return result;

			}
		}
	}

	char res[] = "Wrong number!";
	char* result = new char[14];
	for (size_t i = 0; i < 13; i++)
	{
		result[i] = res[i];
	}
	result[13] = '\0';

	return result;
}