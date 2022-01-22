#include "startScrabble.h"
#include "consoleOperations.h"
#include "constants.h"
#include "fileOperations.h"
#include "helperFunctions.h"
#include <iostream>

using namespace std;

// Visualize Main Menu in the console
void displayMainMenu() {
	printSeparatorLine();

	cout << "Welcome to Scrabble" << endl;
	cout << "1 - Start new game" << endl;
	cout << "2 - Settings" << endl;
	cout << "3 - Add new word" << endl;
	cout << "4 - Quit" << endl;

	printSeparatorLine();

	cout << "Please enter number 1-4" << endl;
}

// Clear console and visualize main menu
void returnToMainMenu() {
	clearConsole();
	displayMainMenu();
}

// Start game
void startGame(int lettersCount, int roundsCount, int availableShuffles) {
	int points = 0;
	int remainingTries = DEFAULT_REMAINING_TRIES;
	int currentRound = 1;

	clearConsole();
	clearInputBuffer();

	while (roundsCount != 0) {
		printSeparatorLine();
		cout << "Your points so far " << points << endl;
		cout << "Round " << currentRound << endl;

		int* letters = generateRandomLetters(lettersCount);
		cout << "Available letters: ";
		for (size_t i = 0; i < LETTERS_COUNT; i++) {
			if (letters[i] >= 1) {
				// in case you have the letter more than one time
				for (size_t j = 0; j < letters[i]; j++) {
					cout << (char)(LOWERCASE_A_ASCII_CODE + i) << " ";
				}
			}
		}

		cout << endl;
		cout << "Enter word: " << endl;

		// check if user have already entered the word
		string inputWord;
		getline(cin, inputWord);

		// if word == 0 - shuffle if available
		if (inputWord == "0") {
			if (availableShuffles > 0) {
				availableShuffles--;
				delete[] letters;
				continue;
			}

			cout << "No shuffles available!" << endl;
		}

		if (!isWordValid(inputWord)) {
			if (remainingTries > 1) {
				remainingTries--;
				cout << "Invalid word. Remaining tries: " << remainingTries << endl;
			}
			else {
				roundsCount--;
				currentRound++;
				remainingTries = DEFAULT_REMAINING_TRIES;
				clearConsole();
			}

			delete[] letters;
			continue;
		}

		// check if word consists only of the letters above
		int* wordArray = convertWordToIntegerArray(inputWord);
		if (!isWordArrayLower(wordArray, letters)) {
			if (remainingTries > 1) {
				remainingTries--;
				cout << "Invalid word. Remaining tries: " << remainingTries << endl;
			}
			else {
				roundsCount--;
				currentRound++;
				remainingTries = DEFAULT_REMAINING_TRIES;
				clearConsole();
			}

			delete[] letters;
			delete[] wordArray;
			continue;
		}

		// check if word is found in dictionary
		if (isWordInDictionary(inputWord)) {
			// Yes - next round + increment points
			points += inputWord.length();
		}
		else {
			// TODO: Discuss
			// No ????
			cout << "You word was not found in the dictionary! Please try again!" << endl;

			delete[] letters;
			delete[] wordArray;
			continue;
		}

		delete[] letters;
		delete[] wordArray;
		roundsCount--;
		currentRound++;
		remainingTries = DEFAULT_REMAINING_TRIES;
		clearConsole();
	}

	// print result
	cout << "Your result is " << points << " (Enter any number to return to main menu)" << endl;
	int inputCode;
	cin >> inputCode;
	returnToMainMenu();
}

// Visualize settings menu and show option for editing values
void displaySettings(int& lettersCount, int& roundsCount, int& shufflesAvailable) {
	clearConsole();
	printSeparatorLine();

	cout << "Current settings:" << endl;
	cout << "Available letters count: " << lettersCount << endl;
	cout << "Rounds count: " << roundsCount << endl;
	cout << "Available shuffles: " << shufflesAvailable << endl;

	printSeparatorLine();

	cout << "Enter 0 start editing the values" << endl;
	cout << "Enter -1 to return to main menu" << endl;

	int inputCode = -2;

	while (true) {
		cin >> inputCode;

		if (inputCode == -1) {
			returnToMainMenu();
			break;
		}

		if (inputCode == 0) {
			cout << "Enter new letters count" << endl;
			int newLettersCount = -1;
			while (newLettersCount < 1 || newLettersCount > LETTERS_COUNT)
			{
				cout << "Please enter number between 1 and 26:" << endl;
				cin >> newLettersCount;
			}

			lettersCount = newLettersCount;

			cout << "Enter new rounds count" << endl;
			int newRoundsCount = -1;
			while (newRoundsCount < 1)
			{
				cout << "Please enter number greater or equal to 1:" << endl;
				cin >> newRoundsCount;
			}

			roundsCount = newRoundsCount;

			cout << "Enter new shuffles count" << endl;
			int newShufflesCount = -1;
			while (newShufflesCount < 1)
			{
				cout << "Please enter number greater or equal to 1:" << endl;
				cin >> newShufflesCount;
			}

			shufflesAvailable = newShufflesCount;

			cout << "The new values were successfully set (Enter any number to return to main menu)" << endl;
			cin >> inputCode;
			returnToMainMenu();
			break;
		}
	}
}

// Visualize add new word screen and show input for new word
void displayAddNewWord() {
	clearConsole();
	printSeparatorLine();

	string newWord;

	clearInputBuffer();

	while (true)
	{
		cout << "Enter new word (consisting only of lowercase letters): " << endl;
		getline(cin, newWord);

		if (isWordValid(newWord)) {
			addWordToFile(newWord);
			returnToMainMenu();
			break;
		}
	}
}


// Start the game
void startScrabble() {
	// srand should not be in the loop where you are generating random numbers
	srand(time(NULL));

	int lettersCount = DEFAULT_LETTERS_COUNT;
	int roundsCount = DEFAULT_ROUNDS_COUNT;
	int availableShuffles = DEFAULT_ROUNDS_SHUFFLES;

	int currentRound = 0;

	int points = 0;

	displayMainMenu();

	int inputNumber = 0;

	while (true) {
		cin >> inputNumber;
		switch (inputNumber)
		{
		case 1: startGame(lettersCount, roundsCount, availableShuffles); break;
		case 2: displaySettings(lettersCount, roundsCount, availableShuffles); break;
		case 3: displayAddNewWord(); break;
		case 4: return; break;
		default: continue; break;
		}
	}
}