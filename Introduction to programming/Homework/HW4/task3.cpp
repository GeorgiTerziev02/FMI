#include <iostream>
using namespace std;

const int MATRIX_SIZE = 10;
const int VARIATIONS_ROWS = 15;
const int VARIATIONS_COLS = 6;

// +1 possible by adding one stick
// -1 possible by removing one stick
// 0 possible by changing the place of one stick in the number
// 2 - impossible change
int possibleChangesMatrix[MATRIX_SIZE][MATRIX_SIZE] = {
	// 0  1  2  3  4  5  6  7  8  9 
	 { 2, 2, 2, 2, 2, 2, 0, 2, 1, 0}, // 0
	 { 2, 2, 2, 2, 2, 2, 2, 1, 2, 2}, // 1
	 { 2, 2, 2, 0, 2, 2, 2, 2, 2, 2}, // 2
	 { 2, 2, 0, 2, 2, 0, 2, 2, 2, 1}, // 3
	 { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}, // 4
	 { 2, 2, 2, 0, 2, 2, 1, 2, 2, 1}, // 5
	 { 0, 2, 2, 2, 2,-1, 2, 2, 1, 0}, // 6
	 { 2,-1, 2, 2, 2, 2, 2, 2, 2, 2}, // 7
	 {-1, 2, 2, 2, 2, 2,-1, 2, 2,-1}, // 8
	 { 0, 2, 2,-1, 2,-1, 0, 2, 1, 2}, // 9
};

void addNewVariant(
	char variations[VARIATIONS_ROWS][VARIATIONS_COLS],
	int& variationIndex,
	int firstNumber,
	char firstSymbol,
	int secondNumber,
	char secondSymbol,
	int thirdNumber
) {
	variations[variationIndex][0] = firstNumber + '0';
	variations[variationIndex][1] = firstSymbol;
	variations[variationIndex][2] = secondNumber + '0';
	variations[variationIndex][3] = secondSymbol;
	variations[variationIndex][4] = thirdNumber + '0';
	variations[variationIndex][5] = '\0';
	variationIndex++;
}

void sortVariations(char variations[VARIATIONS_ROWS][VARIATIONS_COLS], int length) {
	for (size_t i = 0; i < length; i++)
	{
		for (size_t j = i + 1; j < length; j++)
		{
			// compare only the first character
			if ((int)variations[i][0] > (int)variations[j][0]) {
				char temp[6];

				for (size_t k = 0; k < 6; k++)
				{
					temp[k] = variations[i][k];
					variations[i][k] = variations[j][k];
					variations[j][k] = temp[k];
				}
			}
			else if ((int)variations[i][0] == (int)variations[j][0]) {
				// compare the next characters
				for (size_t l = 1; l < 6; l++)
				{
					if ((int)variations[i][l] > (int)variations[j][l]) {
						char temp[6];

						for (size_t k = 0; k < 6; k++)
						{
							temp[k] = variations[i][k];
							variations[i][k] = variations[j][k];
							variations[j][k] = temp[k];
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
	char equation[6];
	cin >> equation;

	int firstNumber = equation[0] - '0';
	char firstSymbol = equation[1];
	int secondNumber = equation[2] - '0';
	char secondSymbol = equation[3];
	int thirdNumber = equation[4] - '0';

	// we will use the three number in an array to escape some if statements
	int equationNumbers[3] = { firstNumber, secondNumber, thirdNumber };
	char variations[VARIATIONS_ROWS][VARIATIONS_COLS];
	int variationIndex = 0;

	// the cases when we move/remove stick to the first symbol(+ => -, - => +) and when we move stick inside a number
	for (size_t i = 0; i < 3; i++)
	{
		int currentNumber = equation[i * 2] - '0';

		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			int operation = possibleChangesMatrix[currentNumber][j];
			equationNumbers[i] = j;

			// case when we remove stick from + => becomes -
			if (firstSymbol == '+' && operation == 1) {
				if (equationNumbers[0] - equationNumbers[1] == equationNumbers[2]) {
					addNewVariant(variations, variationIndex, equationNumbers[0], '-', equationNumbers[1], secondSymbol, equationNumbers[2]);
				}
			}
			// case when we add stick to - => becomes +
			else if (firstSymbol == '-' && operation == -1) {
				if (equationNumbers[0] + equationNumbers[1] == equationNumbers[2]) {
					addNewVariant(variations, variationIndex, equationNumbers[0], '+', equationNumbers[1], secondSymbol, equationNumbers[2]);
				}
			}
			// case when we move stick inside a number
			else if (operation == 0) {
				if ((firstSymbol == '-' && equationNumbers[0] - equationNumbers[1] == equationNumbers[2])
					|| (firstSymbol == '+' && equationNumbers[0] + equationNumbers[1] == equationNumbers[2])) {
					addNewVariant(variations, variationIndex, equationNumbers[0], firstSymbol, equationNumbers[1], secondSymbol, equationNumbers[2]);
				}
			}
		}

		// reset the numbers so that the values are correct
		equationNumbers[0] = firstNumber;
		equationNumbers[1] = secondNumber;
		equationNumbers[2] = thirdNumber;
	}

	// the cases when we make changes only between numbers
	for (size_t i = 0; i < 3; i++)
	{
		int currentNumber = equation[i * 2] - '0';

		for (size_t j = 0; j < MATRIX_SIZE; j++)
		{
			int operation = possibleChangesMatrix[currentNumber][j];
			equationNumbers[i] = j;

			if (operation == 1) {
				// iterate the other numbers forward
				for (size_t l = i + 1; l < 3; l++)
				{
					int nextNumber = equation[l * 2] - '0';
					for (size_t k = 0; k < MATRIX_SIZE; k++)
					{
						int secondOperation = possibleChangesMatrix[nextNumber][k];
						equationNumbers[l] = k;

						if (secondOperation == -1)
						{
							if ((firstSymbol == '-' && equationNumbers[0] - equationNumbers[1] == equationNumbers[2])
								|| (firstSymbol == '+' && equationNumbers[0] + equationNumbers[1] == equationNumbers[2])) {
								addNewVariant(variations, variationIndex, equationNumbers[0], firstSymbol, equationNumbers[1], secondSymbol, equationNumbers[2]);
							}
						}
					}

					if (l == 1) {
						equationNumbers[1] = secondNumber;
						equationNumbers[2] = thirdNumber;
					}
					else if (l == 2) {
						equationNumbers[2] = thirdNumber;
					}
				}
			}
			else if (operation == -1) {
				// iterate the other numbers forward
				for (size_t l = i + 1; l < 3; l++)
				{
					int nextNumber = equation[l * 2] - '0';
					for (size_t k = 0; k < MATRIX_SIZE; k++)
					{
						int secondOperation = possibleChangesMatrix[nextNumber][k];
						equationNumbers[l] = k;

						if (secondOperation == 1)
						{
							if ((firstSymbol == '-' && equationNumbers[0] - equationNumbers[1] == equationNumbers[2])
								|| (firstSymbol == '+' && equationNumbers[0] + equationNumbers[1] == equationNumbers[2])) {
								addNewVariant(variations, variationIndex, equationNumbers[0], firstSymbol, equationNumbers[1], secondSymbol, equationNumbers[2]);
							}
						}
					}


					if (l == 1) {
						equationNumbers[1] = secondNumber;
						equationNumbers[2] = thirdNumber;
					}
					else if (l == 2) {
						equationNumbers[2] = thirdNumber;
					}
				}
			}
		}

		// reset the numbers so that the values are correct
		equationNumbers[0] = firstNumber;
		equationNumbers[1] = secondNumber;
		equationNumbers[2] = thirdNumber;
	}


	if (variationIndex == 0) {
		cout << "No";
	}
	else {
		sortVariations(variations, variationIndex);

		for (size_t i = 0; i < variationIndex; i++)
		{
			cout << variations[i] << endl;
		}
	}

	return 0;
}