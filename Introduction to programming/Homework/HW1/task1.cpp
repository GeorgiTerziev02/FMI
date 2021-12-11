/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 1
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
    short int number;
    cin >> number;

    if (number < 0 || number > 9)
    {
        cout << -1;
        return 0;
    }

    for (short i = 0; i < number; i++)
    {
        for (short k = 0; k < i; k++)
        {
            cout << " ";
        }

        for (short j = i + 1; j <= number; j++)
        {
            cout << j;
        }

        cout << endl;
    }

    for (short i = 1; i < number; i++)
    {
        for (short k = 0; k < number - 1; k++)
        {
            cout << " ";
        }

        for (short j = number; j >= number - i; j--)
        {
            cout << j;
        }

        cout << endl;
    }

    return 0;
}