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
* Cpp file with the implementation of the add new word functionality
*
*/

#include "addNewWord.h"
#include "consoleOperations.h"
#include "fileOperations.h"
#include "helperFunctions.h"
#include <iostream>
#include <string>

// Visualize add new word screen and show input for new word
void addNewWord() {
	clearConsole();
	printSeparatorLine();

	string newWord;
	//clearInputBuffer();

	while (true) {
		cout << "Enter new word (consisting only of lowercase letters): " << endl;
		getline(cin, newWord);

		if (isWordValid(newWord)) {
			addWordToFile(newWord);
			returnToMainMenu();
			break;
		}
	}
}