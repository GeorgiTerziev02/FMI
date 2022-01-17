#include <iostream>

using namespace std;

const int MIN_ARRAY_LENGTH = 3;
const int MAX_ARRAY_LENGTH = 1000;
const int ERROR_EXIT_CODE = -1;

bool isArrayHacksaw(int* array, int index, int arrayLength) {
	if (index == arrayLength - 1) {
		return true;
	}

	int previousNumber = array[index - 1];
	int currentNumber = array[index];
	int nextNumber = array[index + 1];

	if ((previousNumber < currentNumber && currentNumber > nextNumber)
		|| (previousNumber > currentNumber && currentNumber < nextNumber)) {
		return isArrayHacksaw(array, index + 1, arrayLength);
	}

	return false;
}

int main()
{
	int n;
	cin >> n;

	if (n < MIN_ARRAY_LENGTH || n > MAX_ARRAY_LENGTH) {
		cout << ERROR_EXIT_CODE;
		return 0;
	}

	int* numbersArray = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> numbersArray[i];
	}

	bool isHacksaw = isArrayHacksaw(numbersArray, 1, n);

	delete[] numbersArray;

	cout << (isHacksaw ? "yes" : "no");

	return 0;
}