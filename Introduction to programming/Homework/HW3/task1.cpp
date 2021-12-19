/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 1
* @compiler VC
*
*/

#include <iostream>
using namespace std;

size_t strLength(const char str[]) {
	size_t length = 0;
	while (str[length] != '\0') length++;
	
	return length;
}

char* subStr(const char* str, int fromIndex, int toIndex) {
	char* result = new char[toIndex - fromIndex];
	for (int i = 0; i < toIndex - fromIndex + 1; i++)
	{
		result[i] = str[fromIndex + i];
	}
	result[toIndex - fromIndex + 1] = '\0';

	return result;
}

int min(int n, int m) {
	return n > m ? m : n;
}

bool isCorrect(const char sequence[][20], int sequenceSize) {

	for (int i = 1; i < sequenceSize; i++) {
		int prevWordLength = strLength(sequence[i - 1]);
		int currentWordLength = strLength(sequence[i]);

		int lengthDiff = prevWordLength - currentWordLength;

		if (lengthDiff > 1 || lengthDiff < -1) {
			return false;
		}

		int smallerLength = min(prevWordLength, currentWordLength);

		// in case we have two totally equal words in a row
		bool hasDifference = false;

		// find the index of the first different character and search for other
		for (int j = 0; j < smallerLength; j++) {
			if (sequence[i - 1][j] != sequence[i][j]) {
				hasDifference = true;
				if (prevWordLength == currentWordLength) {
					// check that all other characters till the end are the same
					for (int k = j + 1; k < smallerLength; k++) {
						if (sequence[i - 1][k] != sequence[i][k]) {
							return false;
						}
					}
				}

				if (prevWordLength > currentWordLength) {
					// character was removed
					for (int k = j + 1; k < smallerLength + 1; k++) {
						if (sequence[i - 1][k] != sequence[i][k - 1]) {
							return false;
						}
					}
				}

				if (prevWordLength < currentWordLength) {
					// character was added
					for (int k = j; k < smallerLength; k++) {
						if (sequence[i - 1][k] != sequence[i][k + 1]) {
							return false;
						}
					}
				}

				break;
			}
		}

		if (prevWordLength == currentWordLength && !hasDifference) {
			return false;
		}
	}

	return true;
}

const int wordsArrayLength = 50;
const int wordsArrayMinLength = 2;
const int wordLength = 20;

int main()
{
	int length;
	cin >> length;

	if (length < wordsArrayMinLength || length > wordsArrayLength) {
		cout << -1;
		return 0;
	}

	char sequence[wordsArrayLength][wordLength];
	for (short i = 0; i < length; i++) {
		cin>>sequence[i];
	}

	cout << boolalpha << isCorrect(sequence, length);

	return 0;
}