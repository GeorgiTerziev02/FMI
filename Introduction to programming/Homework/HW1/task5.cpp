/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 5
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
	long long int number;
	cin >> number;

	if (number < 0)
	{
		cout << -1;
		return 0;
	}

	int i = 0;
	bool allEven = true;
	long long int newNum = 0;

	while (number != 0)
	{
		short currentNum = number % 10;
		if (currentNum % 2 != 0)
		{
			allEven = false;
			newNum += (number % 10) * pow(10, i);
			i++;
		}

		number /= 10;
	}

	if (allEven)
	{
		cout << 0;
	}
	else
	{
		cout << newNum;
	}

	return 0;
}