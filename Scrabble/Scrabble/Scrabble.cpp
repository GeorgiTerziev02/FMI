#include <iostream>
#include <stdlib.h>		// srand
#include<time.h>		// time

using namespace std;

const int DEFAULT_LETTERS_COUNT = 10;
const int DEFAULT_ROUNDS_COUNT = 5;
const int LETTERS_COUNT = 26;

void clearConsole() {
	system("cls");
}

void resetArray(int* arr, int length) {
	for (size_t i = 0; i < length; i++)
		arr[i] = NULL;
}

int generateRandomInteger(int minValue, int maxValue) {
	if (maxValue < minValue) {
		return 0;
	}

	srand(time(0));

	return (rand() % (maxValue - minValue)) + minValue;
}

// returns array with value = 1 on the index of a letter
int* generateRandomLetters(int count) {
	int* lettersArray = new int[LETTERS_COUNT];
	resetArray(lettersArray, LETTERS_COUNT);

	if (count >= LETTERS_COUNT) {
		// TODO: return the array of all letters
	}

	// TODO: improve it (not optimal)
	while (count > 0) {
		int letter = generateRandomInteger(0, 27);
		if (lettersArray[letter] != NULL) {
			
			lettersArray[letter] = 1;
			count--;
		}
	}

	return lettersArray;
}

int main()
{
	int lettersCount = DEFAULT_LETTERS_COUNT;
	int roundCount = DEFAULT_ROUNDS_COUNT;

	int points = 0;
}