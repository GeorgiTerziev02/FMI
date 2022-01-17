#include <iostream>

using namespace std;

const int LOWERCASE_A_ASCII_CODE = 97;
const int LOWERCASE_Z_ASCII_CODE = 122;

const int UPPERCASE_A_ASCII_CODE = 65;
const int UPPERCASE_Z_ASCII_CODE = 90;

int stringLength(char* str) {
	int index = 0;
	while (str[index] != '\0') index++;

	return index;
}

int letterCharactersCount(char* str) {
	int count = 0;
	int index = 0;

	while (str[index] != '\0') {
		int asciiIndex = (int)str[index];
		if (LOWERCASE_A_ASCII_CODE <= asciiIndex && asciiIndex <= LOWERCASE_Z_ASCII_CODE) {
			count++;
		}

		index++;
	}

	return count;
}

// if upper -> to lower, else if lower -> upper
void transformLetter(char* str, int index) {
	if (str[index] >= UPPERCASE_A_ASCII_CODE && str[index] <= UPPERCASE_Z_ASCII_CODE)
	{
		str[index] = str[index] + 32;
	}
	else if (str[index] >= LOWERCASE_A_ASCII_CODE && str[index] <= LOWERCASE_Z_ASCII_CODE)
	{
		str[index] = str[index] - 32;
	}
}

int mathPow(int number, int degree) {
	int result = 1;
	for (size_t i = 0; i < degree; i++)
	{
		result *= number;
	}

	return result;
}

char** letterCasePermutation(char* str) {
	int lettersCount = letterCharactersCount(str);
	int strLength = stringLength(str);
	int arrayLength = mathPow(2, lettersCount);

	char** arrayOfPermutations = new char* [arrayLength];
	for (size_t i = 0; i < arrayLength; i++)
	{
		arrayOfPermutations[i] = new char[strLength + 1];
	}

	// add the lowercase variation of the word to first position
	for (int i = 0; i < strLength; i++)
	{
		arrayOfPermutations[0][i] = str[i];
	}
	arrayOfPermutations[0][strLength] = '\0';

	int currentIndex = 1;

	for (int i = 0; i < strLength; i++)
	{
		transformLetter(str, i);

		// if made to upper add new permutation
		if (str[i] >= UPPERCASE_A_ASCII_CODE && str[i] <= UPPERCASE_Z_ASCII_CODE) {
			// add new permutation to the array
			for (size_t j = 0; j < strLength; j++)
			{
				arrayOfPermutations[currentIndex][j] = str[j];
			}
			arrayOfPermutations[currentIndex][strLength] = '\0';
			currentIndex++;

			i = -1; // return index to start

			// needed count reached
			if (currentIndex == arrayLength) {
				break;
			}
		}
	}

	return arrayOfPermutations;
}


void sortPermutations(char**& permutations, int rows, int cols) {
	for (size_t i = 0; i < rows; i++)
	{
		for (size_t j = i + 1; j < rows; j++)
		{
			// compare only the first character
			if ((int)permutations[i][0] < (int)permutations[j][0]) {
				int temp = 0;

				// swap
				for (size_t k = 0; k < cols; k++)
				{
					temp = permutations[i][k];
					permutations[i][k] = permutations[j][k];
					permutations[j][k] = temp;
				}
			}
			else if ((int)permutations[i][0] == (int)permutations[j][0]) {
				// compare the next characters
				for (size_t l = 1; l < cols; l++)
				{
					if ((int)permutations[i][l] < (int)permutations[j][l]) {
						int temp = 0;

						// swap
						for (size_t k = 0; k < cols; k++)
						{
							temp = permutations[i][k];
							permutations[i][k] = permutations[j][k];
							permutations[j][k] = temp;
						}

						break;
					}
				}
			}
		}
	}
}

int main()
{
	char* str = new char[300];
	cin.getline(str, 300);

	int lettersCount = letterCharactersCount(str);
	char** result = letterCasePermutation(str);

	int arrayLength = mathPow(2, lettersCount);

	sortPermutations(result, arrayLength, stringLength(str));

	for (int i = 0; i < arrayLength; i++)
	{
		if (i != 0) {
			cout << " ";
		}

		cout << result[i];
	}

	delete[] str;
	for (int i = 0; i < arrayLength; i++)
	{
		delete[] result[i];
	}

	delete[] result;

	return 0;
}