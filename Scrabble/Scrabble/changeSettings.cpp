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
* <Cpp file with the implementation of the change settings functionality>
*
*/

#include "changeSettings.h"
#include "consoleOperations.h"
#include "constants.h"
#include "helperFunctions.h"
#include <string>
#include <iostream>

using namespace std;

// Visualize settings menu and show option for editing values
void changeSettings(int& lettersCount, int& roundsCount, int& shufflesAvailable) {
	clearConsole();
	displaySettings(lettersCount, roundsCount, shufflesAvailable);

	int inputCode = -2;
	string inputCodeString;

	while (true) {
		getline(cin, inputCodeString);
		if (!isInputInteger(inputCodeString)) {
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
			while (newLettersCount < 1 || newLettersCount > LETTERS_COUNT) {
				cout << "Please enter number between 1 and 26:" << endl;
				getline(cin, input);

				if (isInputInteger(input)) {
					newLettersCount = intParse(input);
				}
			}

			lettersCount = newLettersCount;

			cout << "Enter new rounds count" << endl;
			int newRoundsCount = -1;
			while (newRoundsCount < 1) {
				cout << "Please enter number greater or equal to 1:" << endl;
				getline(cin, input);

				if (isInputInteger(input)) {
					newRoundsCount = intParse(input);
				}
			}

			roundsCount = newRoundsCount;

			cout << "Enter new shuffles count" << endl;
			int newShufflesCount = -1;
			while (newShufflesCount < 1) {
				cout << "Please enter number greater or equal to 1:" << endl;
				getline(cin, input);

				if (isInputInteger(input)) {
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