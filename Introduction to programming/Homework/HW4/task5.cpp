#include <iostream>

using namespace std;

bool isZeroLine(int** matrix, int row) {
	for (size_t i = 0; i < 4; i++)
	{
		if (matrix[row][i] != 0) return false;
	}

	return true;
}

int matrixLength(int** matrix, int rows) {
	int length = 0;
	for (size_t i = 0; i < rows; i++)
	{
		if (!isZeroLine(matrix, i))
		{
			length++;
		}
	}

	return length;
}

void printMatrix(int** matrix, int rows) {
	for (size_t i = 0; i < rows; i++)
	{
		if (isZeroLine(matrix, i))
		{
			continue;
		}

		for (size_t j = 0; j < 4; j++)
		{
			cout << matrix[i][j] << " ";
		}

		cout << endl;
	}
}

void clearEquivalentRows(int** matrix, int rows) {
	for (size_t i = 0; i < rows - 1; i++)
	{
		if (isZeroLine(matrix, i))
		{
			continue;
		}

		for (size_t j = i + 1; j < rows; j++)
		{
			if (isZeroLine(matrix, j))
			{
				continue;
			}
			// TODO: might not be possible to divide
			// matrix[i][0] / matrix[j][0] might not be a whole number
			int multiplier = 0;
			bool isEqual = true;

			for (size_t k = 0; k < 4; k++)
			{
				if (matrix[i][k] == k && matrix[j][k] == 0) {
					continue;
				}

				if ((matrix[i][k] != 0 && matrix[j][k] == 0) ||
					(matrix[i][k] == 0 && matrix[j][k] != 0))
				{
					isEqual = false;
					break;
				}

				int innerMultiplier = 0;
				if (matrix[i][k] > matrix[j][k]) {
					innerMultiplier = matrix[i][k] / matrix[j][k];
				}
				else {
					innerMultiplier = matrix[i][k] / matrix[j][k];
				}

				if (multiplier != 0 && multiplier != innerMultiplier)
				{
					isEqual = false;
					break;
				}
				else {
					multiplier = innerMultiplier;
				}
			}

			if (isEqual) {
				for (size_t k = 0; k < 4; k++)
				{
					matrix[i][k] == 0;
				}
			}
		}
	}
}

void simplifyMatrix(int** matrix, int rows) {

	for (size_t col = 0; col < 4; col++)
	{
		for (size_t row = 0; row < rows - 1; row++)
		{
			if (isZeroLine(matrix, row)) {
				continue;
			}

			for (size_t nextRow = row + 1; nextRow < rows; nextRow++)
			{
				if (isZeroLine(matrix, nextRow)) {
					continue;
				}

				int divider = 0;
				if (matrix[nextRow][col] > matrix[row][col] && matrix[row][col] != 0)
				{
					divider = matrix[nextRow][col] / matrix[row][col];

					for (size_t i = 0; i < 4; i++)
					{
						matrix[nextRow][i] -= divider * matrix[row][i];
					}
				}
				else if (matrix[nextRow][col] != 0) {
					divider = matrix[row][col] / matrix[nextRow][col];

					for (size_t i = 0; i < 4; i++)
					{
						matrix[row][i] -= divider * matrix[nextRow][i];
					}
				}

				clearEquivalentRows(matrix, rows);
			}

			clearEquivalentRows(matrix, rows);
		}
	}
}

void createMatrix(int** matrix, int length) {
	for (size_t i = 0; i < length; i++)
	{
		matrix[i] = new int[4];
		for (size_t j = 0; j < 4; j++)
		{
			cin >> matrix[i][j];
		}
	}
}

void deleteMatrix(int** matrix, int length) {
	for (size_t i = 0; i < length; i++)
	{
		delete[] matrix[i];
	}

	delete[] matrix;
}

void createCombinedBasis(int** combinedBasisMatrix, int combinedBasisLength, int** aMatrix, int aMatrixRows, int** bMatrix, int bMatrixRows) {

	for (size_t i = 0; i < combinedBasisLength; i++)
	{
		combinedBasisMatrix[i] = new int[4];
	}

	int currentRow = 0;
	for (size_t i = 0; i < aMatrixRows; i++)
	{
		if (!isZeroLine(aMatrix, i)) {
			for (size_t j = 0; j < 4; j++)
			{
				combinedBasisMatrix[currentRow][j] = aMatrix[i][j];
			}

			currentRow++;
		}
	}
	for (size_t i = 0; i < bMatrixRows; i++)
	{
		if (!isZeroLine(bMatrix, i)) {
			for (size_t j = 0; j < 4; j++)
			{
				combinedBasisMatrix[currentRow][j] = bMatrix[i][j];
			}

			currentRow++;
		}
	}
}

int** getBasisFromHomogeneousSystem(int** matrix, int rows) {
	// get only the non zero lines
	int leftLines = matrixLength(matrix, rows);
	int parameters = 4 - leftLines;

	//TODO...

	return NULL;
}

int main()
{
	int bMatrixRows, aMatrixRows;
	cin >> bMatrixRows;
	cin >> aMatrixRows;

	int** aMatrix = new int* [aMatrixRows];
	createMatrix(aMatrix, aMatrixRows);

	int** bMatrix = new int* [bMatrixRows];
	createMatrix(bMatrix, bMatrixRows);

	simplifyMatrix(aMatrix, aMatrixRows);
	simplifyMatrix(bMatrix, bMatrixRows);

	int combinedBasisLength = matrixLength(aMatrix, aMatrixRows) + matrixLength(bMatrix, bMatrixRows);
	int** combinedBasisMatrix = new int* [combinedBasisLength];
	createCombinedBasis(combinedBasisMatrix, combinedBasisLength, aMatrix, aMatrixRows, bMatrix, bMatrixRows);

	simplifyMatrix(combinedBasisMatrix, combinedBasisLength);
	printMatrix(combinedBasisMatrix, combinedBasisLength);

	deleteMatrix(aMatrix, aMatrixRows);
	deleteMatrix(bMatrix, bMatrixRows);
	deleteMatrix(combinedBasisMatrix, combinedBasisLength);
}