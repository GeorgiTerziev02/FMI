#include "helperFunctions.h"
#include "constants.h"
#include <stdlib.h>		// srand
#include <string>

using namespace std;

// Set all values in the array to 0
void resetArray(int* arr, int length) {
	for (size_t i = 0; i < length; i++)
		arr[i] = 0;
}

// Generate random integer in the given range
int generateRandomInteger(int minValue, int maxValue) {
	if (maxValue < minValue) {
		return 0;
	}

	return (rand() % (maxValue - minValue)) + minValue;
}

// Returns array with indexes - alphabet letter
// and values - count of the used letter
int* generateRandomLetters(int count) {
	int* lettersArray = new int[LETTERS_COUNT];
	resetArray(lettersArray, LETTERS_COUNT);

	while (count > 0) {
		int letter = generateRandomInteger(0, LETTERS_COUNT);
		lettersArray[letter]++;
		count--;
	}

	return lettersArray;
}


// Generate array with indexes - alphabet letter
// and values - count of the used letter
int* convertWordToIntegerArray(string word) {
	int* wordArray = new int[LETTERS_COUNT];
	resetArray(wordArray, LETTERS_COUNT);

	for (size_t i = 0; i < word.length(); i++) {
		wordArray[(int)word[i] - LOWERCASE_A_ASCII_CODE]++;
	}

	return wordArray;
}

// check if array consists only of the given letters
// the whole alphabet is the size of the arrays, otherwise we should pass the length as well
bool isWordArrayLower(int* arr1, int* arr2) {
	for (size_t i = 0; i < LETTERS_COUNT; i++) {
		if (arr1[i] > arr2[i]) {
			return false;
		}
	}

	return true;
}

// Check if all characters in the word are lowercase
bool isWordValid(string word) {
	if (word.length() < 1) {
		return false;
	}

	for (size_t i = 0; i < word.length(); i++) {
		int asciiCode = (int)word[i];
		if (asciiCode < LOWERCASE_A_ASCII_CODE || asciiCode > LOWERCASE_Z_ASCII_CODE) {
			return false;
		}
	}

	return true;
}