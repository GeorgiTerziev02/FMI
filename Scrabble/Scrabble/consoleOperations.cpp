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
