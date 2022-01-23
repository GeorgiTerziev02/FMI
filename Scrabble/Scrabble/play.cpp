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
* Cpp file with the implementation of the play functionality
*
*/

#include "play.h"
#include "constants.h"
#include "helperFunctions.h"
#include "consoleOperations.h"
#include "fileOperations.h"

#include <iostream>

using namespace std;

// Start playing Scrabble game
void play(int lettersCount, int roundsCount, int availableShuffles) {
	int points = 0;
	int remainingTries = DEFAULT_REMAINING_TRIES;
	int currentRound = 1;

	//clearInputBuffer();
	clearConsole();

	int* letters = generateRandomLetters(lettersCount);
	bool shouldGetNewLetters = false;

	while (roundsCount != 0) {
		printSeparatorLine();
		cout << "Your points so far " << points << endl;
		cout << "Round " << currentRound << endl;

		if (shouldGetNewLetters) {
			delete[] letters;
			letters = generateRandomLetters(lettersCount);
		}

		displayAvailableLetters(letters);

		cout << "Enter word consisting of lowercase characters: " << endl;

		// check if user have already entered the word
		string inputWord;
		getline(cin, inputWord);

		// if word == 0 - shuffle if available
		if (inputWord == "0") {
			if (availableShuffles > 0) {
				availableShuffles--;
				shouldGetNewLetters = true;
				continue;
			}

			cout << "No shuffles available!" << endl;
			shouldGetNewLetters = false;
			continue;
		}

		// check if word is valid (contains only lowercase characters)
		if (!isWordValid(inputWord)) {
			if (remainingTries > 1) {
				remainingTries--;
				cout << "Invalid word. Remaining tries: " << remainingTries << endl;
				shouldGetNewLetters = false;
			}
			else {
				roundsCount--;
				currentRound++;
				remainingTries = DEFAULT_REMAINING_TRIES;
				shouldGetNewLetters = true;
				clearConsole();
			}

			continue;
		}

		// check if word consists only of the letters above
		int* wordArray = convertWordToIntegerArray(inputWord);
		if (!isWordArrayLower(wordArray, letters)) {
			if (remainingTries > 1) {
				remainingTries--;
				cout << "Invalid word. Remaining tries: " << remainingTries << endl;
				shouldGetNewLetters = false;
			}
			else {
				roundsCount--;
				currentRound++;
				shouldGetNewLetters = true;
				remainingTries = DEFAULT_REMAINING_TRIES;
				clearConsole();
			}

			delete[] wordArray;
			continue;
		}

		// check if word is found in dictionary
		if (isWordInDictionary(inputWord)) {
			// Yes - next round + increment points
			points += inputWord.length();
		}
		else {
			cout << "You word was not found in the dictionary! Please try again!" << endl;
			shouldGetNewLetters = false;
			delete[] wordArray;
			continue;
		}

		delete[] wordArray;
		roundsCount--;
		shouldGetNewLetters = true;
		currentRound++;
		remainingTries = DEFAULT_REMAINING_TRIES;
		clearConsole();
	}

	delete[] letters;
	// print result
	cout << "Your result is " << points << " (Press enter to return to main menu)" << endl;
	string input;
	getline(cin, input);
	returnToMainMenu();
}