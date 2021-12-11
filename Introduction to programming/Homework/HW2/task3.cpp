/**
*
* Solution to homework assignment 2
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

// doing the reversed operations so that
// we can easily use that if the destination number is odd we have only the option to add one and then divide
// divide by 2
// add one

int reversedMinOperations(int startNumber, int destinationNumber) {
	int counter = 0;

	while (startNumber != destinationNumber)
	{
		if (destinationNumber > startNumber) {
			if (destinationNumber % 2 != 0) {
				destinationNumber ++;
			}
			else {
				destinationNumber /= 2;
			}
		}
		else {
			// case when we have gone below the destinationNumber we have the only option to increment
			destinationNumber++;
		}

		counter++;
	}

	return counter;
}

int main()
{
	int startNumber, destinationNumber;
	cin >> startNumber >> destinationNumber;

	if (startNumber <= 0 && destinationNumber > 0) {
		cout << -1;
		return 0;
	}

	if (startNumber >= destinationNumber) {
		// you have to subtract 1 until you reach the destionation Number
		cout << startNumber - destinationNumber;
		return 0;
	}

	cout << reversedMinOperations(startNumber, destinationNumber);

	return 0;
}