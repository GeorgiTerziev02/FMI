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
* <Cpp file setting up the game functionalities>
*
*/

#include "startScrabble.h"
#include "constants.h"
#include "consoleOperations.h"
#include "helperFunctions.h"
#include "play.h"
#include "changeSettings.h"
#include "addNewWord.h"
#include <iostream>

using namespace std;

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

		if (isInputInteger(input)) {
			int inputNumber = intParse(input);
			switch (inputNumber)
			{
			case 1: play(lettersCount, roundsCount, availableShuffles); break;
			case 2: changeSettings(lettersCount, roundsCount, availableShuffles); break;
			case 3: addNewWord(); break;
			case 4: return; break;
			default: cout << "Please enter number 1-4" << endl; break;
			}
		}
		else {
			cout << "Please enter number 1-4" << endl;
		}
	}
}