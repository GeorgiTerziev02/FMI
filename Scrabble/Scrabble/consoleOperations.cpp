#include "consoleOperations.h"
#include "constants.h"  // constants
#include <iostream>

using namespace std;

// Visualize a separator line in the console 
void printSeparatorLine() {
	for (size_t i = 0; i < HEADER_SEPARATOR_LENGTH; i++)
		cout << HEADER_SEPARATOR;
	cout << endl;
}

void clearConsole() {
	system("cls");
}

// Remove all error flags and characters from the input buffer
void clearInputBuffer() {
	// because of using both getline and cin we have to cin.ignore;
	// cin leaves the newline character in the stream which will be read as input from the getline

	// clears errors flags from the cin
	cin.clear();
	// discard unread characters from the input buffer
	cin.sync();
	// discard characters from the input buffer
	cin.ignore();
}

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

// Visualize Settings in the console
void displaySettings(const int& lettersCount, const int& roundsCount, const int& shufflesAvailable) {
	printSeparatorLine();

	cout << "Current settings:" << endl;
	cout << "Available letters count: " << lettersCount << endl;
	cout << "Rounds count: " << roundsCount << endl;
	cout << "Available shuffles: " << shufflesAvailable << endl;

	printSeparatorLine();

	cout << "Enter 0 start editing the values" << endl;
	cout << "Enter -1 to return to main menu" << endl;

}