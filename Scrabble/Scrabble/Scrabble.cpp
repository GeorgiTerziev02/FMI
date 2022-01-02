#include <iostream>
#include <stdlib.h>		// srand
#include<time.h>		// time
#include<sstream>		// stream
#include<fstream>		// files

using namespace std;

const int DEFAULT_LETTERS_COUNT = 10;
const int DEFAULT_ROUNDS_COUNT = 5;
const int DEFAULT_ROUNDS_SHUFFLES = 2;
const int LETTERS_COUNT = 26;
const int LOWERCASE_A_ASCII_CODE = 97;
const int LOWERCASE_Z_ASCII_CODE = 122;

const char HEADER_SEPARATOR = '=';

void printSeparatorLine() {
	for (size_t i = 0; i < 25; i++)
		cout << HEADER_SEPARATOR;
	cout << endl;
}

void clearConsole() {
	system("cls");
}

void clearInputBuffer() {
	// because of using both getline and cin we have to cin.ignore;
	// cin leaves the newline character in the stream which will be read as input from the getline
	cin.clear();
	cin.sync();
	cin.ignore();
}

void resetArray(int* arr, int length) {
	for (size_t i = 0; i < length; i++)
		arr[i] = 0;
}

int generateRandomInteger(int minValue, int maxValue) {
	if (maxValue < minValue) {
		return 0;
	}

	return (rand() % (maxValue - minValue)) + minValue;
}

// returns array with value = 1 on the index of a letter
int* generateRandomLetters(int count) {
	int* lettersArray = new int[LETTERS_COUNT];
	resetArray(lettersArray, LETTERS_COUNT);

	if (count >= LETTERS_COUNT) {
		// TODO: return the array of all letters
	}

	while (count > 0) {
		int letter = generateRandomInteger(0, 27);
		lettersArray[letter]++;
		count--;
	}

	return lettersArray;
}

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

int* convertWordToIntegerArray(string word) {
	int* wordArray = new int[LETTERS_COUNT];
	resetArray(wordArray, LETTERS_COUNT);

	for (size_t i = 0; i < word.length(); i++) {
		wordArray[(int)word[i] - LOWERCASE_A_ASCII_CODE]++;
	}

	return wordArray;
}

// the whole alphabet is the size of the arrays, otherwise we should pass the length as well
bool areWordArraysEqual(int* arr1, int* arr2) {
	for (size_t i = 0; i < LETTERS_COUNT; i++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}

	return true;
}

void returnToMainMenu() {
	clearConsole();
	displayMainMenu();
}

void startGame(int lettersCount, int roundsCount, int availableShuffles) {
	int points = 0;
	int remainingTries = 3;
	
	clearInputBuffer();

	while (roundsCount != 0) {
		clearConsole();
		printSeparatorLine();

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

		cout << "Enter word!: " << endl;

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

		// check if word consists only of the letters above
		int* wordArray = convertWordToIntegerArray(inputWord);
		if (!areWordArraysEqual(letters, wordArray)) {
			if (remainingTries != 0) {
				remainingTries--;
				cout << "Invalid word. Remaining tries: " << endl;
			}
			else {
				roundsCount--;
			}
			delete[] letters;
			delete[] wordArray;
			continue;
		}

		// check if word is found in dictionary
		  // Yes - next round + increment points
		  points += inputWord.size();
		  // No - ???
		

		delete[] letters;
		delete[] wordArray;
		roundsCount--;
		remainingTries = 3;
		clearConsole();
	}

	// print result
	cout << "Your result is " << points << " (Enter any number to return to main menu)" << endl;
	int inputCode;
	cin >> inputCode;
	returnToMainMenu();
}

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
			while (newLettersCount < 1 || newLettersCount > 26)
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

// TODO: add sorting
void addWordToFile(string word) {
	ofstream wordsFile;
	wordsFile.open("words.txt", std::fstream::app);

	wordsFile << word << "\n";

	wordsFile.close();
}

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

// not working???
void quit() {
	system("exit");
}

int main()
{
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
		case 4: return 0; break;
		default: continue; break;
		}
	}

	return 0;
}