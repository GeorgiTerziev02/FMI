/**
*
* Solution to homework assignment 3
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 3
* @compiler VC
*
*/

#include <iostream>
using namespace std;

const int initialAValue = 35;
const int initialBValue = 64;
const int maxAValue = 55;
const int maxBValue = 96;

const char delimeter = '|';

const int passwordArrLength = 7;

int main()
{
	int maxFirstNumber, maxSecondNumber, maxPasswords;
	cin >> maxFirstNumber >> maxSecondNumber >> maxPasswords;

	if (maxFirstNumber < 1 || maxFirstNumber > 1000
		|| maxSecondNumber < 1 || maxSecondNumber>1000
		|| maxPasswords < 1 || maxPasswords > 1000000) {
		cout << -1;
		return 0;
	}

	int aCharacter = initialAValue;
	int bCharacter = initialBValue;
	int firstNumber = 1;
	int secondNumber = 1;

	while (maxPasswords > 0) {
		cout << (char)aCharacter 
			 << (char)bCharacter 
			 << firstNumber 
			 << secondNumber 
			 << (char)bCharacter 
			 << (char)aCharacter 
			 << delimeter;

		aCharacter++;
		bCharacter++;

		if (aCharacter > maxAValue) {
			aCharacter = initialAValue;
		}

		if (bCharacter > maxBValue) {
			bCharacter = initialBValue;
		}

		secondNumber++;

		if (secondNumber > maxSecondNumber) {
			secondNumber = 1;
			firstNumber++;

			if (firstNumber > maxFirstNumber) {
				break;
			}
		}

		maxPasswords--;
	}

	return 0;
}