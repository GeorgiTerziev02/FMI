/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

const int arrLength = 256;

int main()
{
	char initialString[arrLength];
	char smallCharacters[arrLength];
	char bigCharacters[arrLength];

	cin >> initialString;

	int smallIndex = 0;
	int bigIndex = 0;
	int index = 0;

	while (initialString[index] != '\0') {
		int asciiCode = (int)initialString[index];

		if (asciiCode >= 97 && asciiCode <= 122) {
			smallCharacters[smallIndex] = initialString[index];
			smallIndex++;
		}

		if (asciiCode >= 65 && asciiCode <= 90) {
			bigCharacters[bigIndex] = initialString[index];
			bigIndex++;
		}

		index++;
	}

	smallCharacters[smallIndex] = '\0';
	bigCharacters[bigIndex] = '\0';

	// different length
	if (smallIndex != bigIndex) {
		cout << "No";
		return 0;
	}

	for (int i = 0; i < smallIndex; i++) {
		if (smallCharacters[i] - 32 != bigCharacters[i]) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";

	return 0;
}