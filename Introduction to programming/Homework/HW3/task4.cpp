/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int longestSubstrWithUniqueSymbolsLength(const char str[]) {
	int currentMaxLength = 0;
	int lastEndOfSequenceIndex = 0;
	int index = 0;

	while (str[index] != '\0') {
		char currentChar = str[index];
		int counter = 1;

		for (int i = lastEndOfSequenceIndex; i < index; i++) {
			if (str[i] == currentChar) {
				lastEndOfSequenceIndex = i + 1;
				counter = -1;
				break;
			}

			counter++;
		}

		if (counter > currentMaxLength) currentMaxLength = counter;

		index++;
	}

	return currentMaxLength;
}

const int arrLength = 101;

int main()
{
	char str[arrLength];
	cin >> str;

	cout << longestSubstrWithUniqueSymbolsLength(str);

	return 0;
}