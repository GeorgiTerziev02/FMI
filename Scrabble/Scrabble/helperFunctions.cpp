/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @idnumber 3MI0600090
* @compiler VC
*
* Cpp file with the implementation of functions that are needed for the logic of the application
*
*/

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

// Check if string is a valid integer
bool isInputInteger(string str) {
	int length = str.length();
	if (length < 1)
	{
		return false;
	}

	int index = str[0] == DASH_SYMBOL ? 1 : 0;

	// input is "-"
	if (index == length)
	{
		return false;
	}

	for (;index < length; index++)
	{
		if (str[index] < ZERO_DIGIT_SYMBOL || str[index] > NINE_DIGIT_SYMBOL)
		{
			return false;
		}
	}

	return true;
}

// Parse string to integer
int intParse(string str) {
	if (str.length() < 1)
	{
		return 0;
	}

	int index = str[0] == DASH_SYMBOL ? 1 : 0;

	int result = 0;
	for (; index < str.length(); index++)
	{
		result = result * 10 + (str[index] - ZERO_DIGIT_SYMBOL);
	}

	return str[0] == DASH_SYMBOL ? -result : result;
}