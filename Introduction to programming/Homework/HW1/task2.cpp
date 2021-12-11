/**
*
* Solution to homework assignment 1
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @task 2
* @compiler VC
*
*/

#include <iostream>

using namespace std;

int main()
{
    long int number;
    cin >> number;

    if (number <= 0 || number > 1e9)
    {
        cout << -1;
        return 0;
    }

    long int numberToReverse = number;
    long int reversedNumber = 0;
    short int numberLength = 0;

    while (numberToReverse != 0)
    {
        numberLength++;
        reversedNumber = reversedNumber * 10 + numberToReverse % 10;
        numberToReverse /= 10;
    }

    bool isConsoledNumber = false;
    for (short i = 0; i < numberLength / 2; i++)
    {
        short num1 = reversedNumber % 10;
        short num2 = number % 10;

        if (num1 > num2)
        {
            if (!isConsoledNumber)
            {
                cout << num1;
                isConsoledNumber = true;
            }
            else 
            {
                cout << " " << num1;
            }
        }
        else if (num2 > num1) 
        {
            if (!isConsoledNumber)
            {
                cout << num2;
                isConsoledNumber = true;
            }
            else 
            {
                cout << " " << num2;
            }
        }

        reversedNumber /= 10;
        number /= 10;
    }

    if (numberLength % 2 != 0)
    {
        cout << " " << reversedNumber % 10;
    }

    return 0;
}