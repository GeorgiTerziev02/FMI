// Exam.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "solutions.h"

using namespace std;

int main()
{
	cout << newNum(24) << endl;
	cout << newNum(123456789) << endl;
	cout << newNum(578393254) << endl;
	cout << newNum(11200100) << endl;
	cout << newNum(20112001) << endl;

	int arr1[] = { 1,11,3,99,5 };
	int arr2[] = { 4,2,23,0,7 };

	int* result = mergeArr(arr1, arr2, 5);

	for (size_t i = 0; i < 5; i++)
	{
		cout << result[i] << " ";
	}

	cout << endl;

	int test1arr1[] = { 22,5,17,8,90,7,12 };
	int test2arr2[] = { 6,9,18,7,1,2,3 };

	int* result2 = mergeArr(test1arr1, test2arr2, 7);

	for (size_t i = 0; i < 7; i++)
	{
		cout << result2[i] << " ";
	}

	cout << endl;

	char text1[] = "this is A teSt String";
	char text2[] = "a";
	char text3[] = "s";
	cout << getWord(text1, -1) << endl;
	cout << getWord(text1, 1) << endl;
	cout << getWord(text1, 2) << endl;
	cout << getWord(text1, 3) << endl;
	cout << getWord(text1, 4) << endl;
	cout << getWord(text1, 5) << endl;
	cout << getWord(text1, 6) << endl;
	cout << getWord(text2, 1) << endl;
	cout << getWord(text3, 1) << endl;
	cout << getWord(text3, 2) << endl;
	cout << getWord(text3, 5) << endl;
}
