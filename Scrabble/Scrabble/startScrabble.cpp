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
* Cpp file with the function that starts the game
*
*/

#include "startScrabble.h"
#include "consoleOperations.h"
#include "constants.h"
#include "fileOperations.h"
#include "helperFunctions.h"
#include <iostream>

using namespace std;

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

	//clearInputBuffer();
	clearConsole();

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
	cout << "Your result is " << points << " (Press enter to return to main menu)" << endl;
	string input;
	getline(cin, input);
	returnToMainMenu();
}

// Visualize settings menu and show option for editing values
void changeSettings(int& lettersCount, int& roundsCount, int& shufflesAvailable) {
	clearConsole();
	displaySettings(lettersCount, roundsCount, shufflesAvailable);

	int inputCode = -2;
	string inputCodeString;

	while (true) {
		getline(cin, inputCodeString);
		if (!isInputInteger(inputCodeString))
		{
			continue;
		}

		inputCode = intParse(inputCodeString);

		if (inputCode == -1) {
			returnToMainMenu();
			break;
		}

		if (inputCode == 0) {
			cout << "Enter new letters count" << endl;
			string input;
			int newLettersCount = -1;
			while (newLettersCount < 1 || newLettersCount > LETTERS_COUNT)
			{
				cout << "Please enter number between 1 and 26:" << endl;
				getline(cin, input);
				if (isInputInteger(input))
				{
					newLettersCount = intParse(input);
				}
			}

			lettersCount = newLettersCount;

			cout << "Enter new rounds count" << endl;
			int newRoundsCount = -1;
			while (newRoundsCount < 1)
			{
				cout << "Please enter number greater or equal to 1:" << endl;
				getline(cin, input);
				if (isInputInteger(input))
				{
					newRoundsCount = intParse(input);
				}
			}

			roundsCount = newRoundsCount;

			cout << "Enter new shuffles count" << endl;
			int newShufflesCount = -1;
			while (newShufflesCount < 1)
			{
				cout << "Please enter number greater or equal to 1:" << endl;
				getline(cin, input);
				if (isInputInteger(input))
				{
					newShufflesCount = intParse(input);
				}
			}

			shufflesAvailable = newShufflesCount;

			cout << "The new values were successfully set (Press enter to return to main menu)" << endl;
			getline(cin, input);
			returnToMainMenu();
			break;
		}
	}
}

// Visualize add new word screen and show input for new word
void addNewWord() {
	clearConsole();
	printSeparatorLine();

	string newWord;
	//clearInputBuffer();

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

	string input;

	while (true) {
		getline(cin, input);

		if (isInputInteger(input))
		{
			int inputNumber = intParse(input);
			switch (inputNumber)
			{
			case 1: startGame(lettersCount, roundsCount, availableShuffles); break;
			case 2: changeSettings(lettersCount, roundsCount, availableShuffles); break;
			case 3: addNewWord(); break;
			case 4: return; break;
			default: cout << "Please enter number 1-4" << endl; break;
			}
		}
		else 
		{
			cout << "Please enter number 1-4" << endl;
		}
	}
}