#include "fileOperations.h"
#include <sstream>		// stream
#include <fstream>		// files

using namespace std;

// Check if string is in txt file
bool isWordInDictionary(string word) {
	ifstream wordsFile;
	wordsFile.open("words.txt", std::fstream::app);

	if (wordsFile.is_open()) {
		string line;

		while (getline(wordsFile, line))
		{
			if (line == word) {
				return true;
			}
		}

		wordsFile.close();
	}

	return false;
}

// TODO: add sorting
// TODO: check if word is already in file
// Add given string to txt file
void addWordToFile(string word) {
	ofstream wordsFile;
	if (!isWordInDictionary(word))
	{
		return;
	}

	wordsFile.open("words.txt", std::fstream::app);

	wordsFile << word << "\n";

	wordsFile.close();
}