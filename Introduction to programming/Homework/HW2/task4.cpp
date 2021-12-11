/**
*
* Solution to homework assignment 2
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 4
* @compiler VC
*
*/

#include <iostream>

using namespace std;

long int removeNumberAtEnd(long int n) {
	return n / 10;
}

long int addNumberToEnd(long int n, short number) {
	return n * 10 + number;
}

short getNumberLength(long int n) {
	short length = 0;

	while (n != 0) {
		length++;
		n /= 10;
	}

	return length;
}

// counted forward starting from 1
short getNumberPosition(long int n, short number, short startIndex = 0) {
	short index = 0;
	bool isFound = false;
	short position = -1;
	short numberLength = getNumberLength(n);

	while (n != 0){
		if (n % 10 == number && numberLength - index >= startIndex) {
			isFound = true;
			position = numberLength - index;
			break;
		}

		index++;
		n /= 10;
	}

	return position;
}

// search for a number after an index
bool isDigitInNumber(long int n, short digit, short startIndex = 0) {
	short numberLength = getNumberLength(n);
	short index = 0;

	while (n != 0) {
		if (n % 10 == digit && numberLength - index >= startIndex) {
			return true;
		}

		index++;
		n /= 10;
	}

	return false;
}

short getNumberAtPosition(long int n, short position) {
	short index = 0;
	short numberLength = getNumberLength(n);

	while (n != 0) {
		if (numberLength - index == position) {
			return n % 10;
		}

		index++;
		n /= 10;
	}

	return -1;
}

// 123456 index 1 is 1 index 2 is 2
long int changePositions(long int n, short from, short to) {
	long int tempNumber = n;
	long int conversionNumber = 0;
	short numberLength = getNumberLength(n);

	short fromNumber = getNumberAtPosition(n, from);
	short toNumber = getNumberAtPosition(n, to);

	n -= toNumber * pow(10, numberLength - to);
	n += fromNumber * pow(10, numberLength - to);

	n -= fromNumber * pow(10, numberLength - from);
	n += toNumber * pow(10, numberLength - from);

	return n;
}

int main()
{
	long int n, k, tempNumber;
	cin >> n >> k;

	if (n < 0 || k < 0) {
		cout << -1;
		return 0;
	}

	tempNumber = k;

	short operationsCount = 0;
	short nLength = getNumberLength(n);
	short kLength = getNumberLength(k);
	short maxOperations = nLength + kLength;

	if (n == k) {
		cout << operationsCount;
		return 0;
	}

	if (n == 0) {
		cout << kLength;
		return 0;
	}
	
	if (k == 0) {
		cout << nLength + 1;
		return 0;
	}

	short i = 1;

	while (n != k) {
		short lastDigitInN = n % 10;
		if (!isDigitInNumber(k, lastDigitInN)) {
			n = removeNumberAtEnd(n);
			operationsCount++;
			continue;
		}

		if (i > kLength) {
			short newNLength = getNumberLength(n);

			if (newNLength > kLength) {
				operationsCount += newNLength - kLength;
			}

			break;
		}

		short currentDigitFromK = getNumberAtPosition(k, i);

		bool isDigitInN = isDigitInNumber(n, currentDigitFromK, i);

		if (!isDigitInN) {
			n = addNumberToEnd(n, currentDigitFromK);
			operationsCount++;
			continue;
		}

		short currentDigitPositionInN = getNumberPosition(n, currentDigitFromK, i);

		if (currentDigitPositionInN != i) {
			short fromNumber = getNumberAtPosition(n, currentDigitPositionInN);
			short toNumber = getNumberAtPosition(n, i);

			if (fromNumber != toNumber) {
				n = changePositions(n, currentDigitPositionInN, i);
				operationsCount++;
			}
		}

		i++;
	}

	if (maxOperations < operationsCount) {
		cout << maxOperations;
	}
	else {
		cout << operationsCount;
	}

	return 0;
}