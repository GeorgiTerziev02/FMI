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
* <Cpp file with the implementation of the functions working with files>
*
*/

#include "fileOperations.h"
#include <sstream>		// stream
#include <fstream>		// files

using namespace std;

const char DICTIONARY_PATH[] = "words.txt";

// Check if string is in txt file
bool isWordInDictionary(string word) {
	ifstream wordsFile;
	wordsFile.open(DICTIONARY_PATH, std::fstream::app);

	if (wordsFile.is_open()) {
		string line;

		while (getline(wordsFile, line)) {
			if (line == word) {
				wordsFile.close();
				return true;
			}
		}

		wordsFile.close();
	}

	return false;
}

// TODO: add sorting
// Add given string to txt file
void addWordToFile(string word) {
	ofstream wordsFile;

	wordsFile.open(DICTIONARY_PATH, std::fstream::app);
	wordsFile << word << "\n";
	wordsFile.close();
}