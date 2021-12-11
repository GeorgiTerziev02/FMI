/**
*
* Solution to homework assignment 2
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

bool hasAlternatingBits(unsigned n) {
    if (n == 0) return true;

    short lastRemainder = -1;

    while (n != 0) {
        short remainder = n % 2;

        if (lastRemainder == remainder) {
            return false;
        }

        lastRemainder = remainder;
        n /= 2;
    }

    return true;
}

int main()
{
    long int n;
    cin >> n;

    if (n < 0) {
        cout << -1;
        return 0;
    }

    hasAlternatingBits(n) ? cout << "true" : cout << "false";

    return 0;
}