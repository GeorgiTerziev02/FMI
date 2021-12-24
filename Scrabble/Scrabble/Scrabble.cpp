#include <iostream>
#include <stdlib.h>		// srand
#include<time.h>		// time

using namespace std;

const int DEFAULT_LETTERS_COUNT = 10;
const int DEFAULT_ROUNDS_COUNT = 5;
const int DEFAULT_ROUNDS_SHUFFLES = 2;
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


const char HEADER_SEPARATOR = '=';

void printSeparatorLine() {
	for (size_t i = 0; i < 20; i++)
		cout << HEADER_SEPARATOR;
	cout << endl;
}

void displayMainMenu(){
	printSeparatorLine();

	cout << "Welcome to Scrabble" << endl;
	cout << "1 - Start new game" << endl;
	cout << "2 - Settings" << endl;
	cout << "3 - Add new word" << endl;
	cout << "4 - Quit" << endl;

	printSeparatorLine();

	cout << "Please enter number 1-4" << endl;
}

void startGame() {

}

void returnToMainMenu() {
	clearConsole();
	displayMainMenu();
}

void displaySettings(int &lettersCount, int &roundsCount, int &shufflesAvailable) {
	clearConsole();

}

void addNewWord() {

}

void quit() {
	system("exit");
}

int main()
{
	int lettersCount = DEFAULT_LETTERS_COUNT;
	int roundsCount = DEFAULT_ROUNDS_COUNT;
	int availableSchuffles = DEFAULT_ROUNDS_SHUFFLES;

	int currentRound = 0;

	int points = 0;

	displayMainMenu();

	int inputNumber = 0;

	while (true) {
		cin >> inputNumber;
		switch (inputNumber)
		{
			case 1: startGame(); break;
			case 2: displaySettings(lettersCount, roundsCount, availableSchuffles); break;
			case 3: addNewWord(); break;
			case 4: quit(); break;
			default: continue; break;
		}
	}

	return 0;
}