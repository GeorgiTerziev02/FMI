/**
*
* Solution to homework assignment 1
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

int main()
{
	double x, y;
	cin >> x >> y;

	// check if point outside
	if (x > 4.000000 || x < -4.000000 || y > 4.000000 || y < -4.000000)
	{
		cout << "Outside\n";
		return 0;
	}

	double radiusToCenter = x * x + y * y;

	// check if point is on the border of the square or the circle
	if (x == 4.000000 || y == 4.000000 || x == -4.000000 || y == -4.000000 || radiusToCenter == 16.000000)
	{
		cout << "Undefined\n";
		return 0;
	}

	// check if point is between the border of the square and the circle
	if (radiusToCenter > 16.000000)
	{
		cout << "White\n";
		return 0;
	}

	// we will use the squared values of the radiuses
	double radiusToMinusTwo = (-2.0 - x) * (-2.0 - x) + (0.0 - y) * (0.0 - y);
	double radiusToPlusTwo = (2.0 - x) * (2.0 - x) + (0.0 - y) * (0.0 - y);

	// check if point is on border of the small circles
	if (radiusToMinusTwo == 1.000000 || radiusToPlusTwo == 1.000000)
	{
		cout << "Undefined\n";
		return 0;
	}

	// check if point is on the half circles
	if ((radiusToMinusTwo == 4.000000 && y >= 0) || (radiusToPlusTwo == 4.000000 && y <= 0))
	{
		cout << "Undefined\n";
		return 0;
	}

	// check if point is inside the small black circle
	if (radiusToPlusTwo < 1.000000)
	{
		cout << "Black\n";
		return 0;
	}

	// check if point is inside the small white circle
	if (radiusToMinusTwo < 1.000000)
	{
		cout << "White\n";
		return 0;
	}

	// check if point is in the top right sector outside the small circle
	if (radiusToPlusTwo > 1.000000 && x >= 0 && y >= 0)
	{
		cout << "White\n";
		return 0;
	}

	// check if point is in the bottom left sector outside the small circle
	if (radiusToMinusTwo > 1.000000 && x <= 0 && y <= 0)
	{
		cout << "Black\n";
		return 0;
	}

	// check if point is in the left black half circle
	if (radiusToMinusTwo > 1.000000 && radiusToMinusTwo < 4.000000 && x <= 0 && y >= 0)
	{
		cout << "Black\n";
		return 0;
	}

	// check if point is in the right white half circle
	if (radiusToPlusTwo > 1.000000 && radiusToPlusTwo < 4.000000 && x >= 0 && y <= 0)
	{
		cout << "White\n";
		return 0;
	}

	// check if point is in the what is left from the left top sector
	if (radiusToMinusTwo > 4.000000 && x <= 0 && y >= 0)
	{
		cout << "White\n";
		return 0;
	}

	// check if point is in the what is left from the bottom right sector
	if (radiusToPlusTwo > 4.000000 && x >= 0 && y <= 0)
	{
		cout << "Black\n";
		return 0;
	}

	return 0;
}