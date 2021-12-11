/**
*
* Solution to homework assignment 2
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

bool isPalindrome(long int number) {
    long int initialNumber = number;
    long int reversedNumber = 0;

    while (number > 0) {
        reversedNumber = reversedNumber * 10 + number % 10;
        number /= 10;
    }

    return initialNumber == reversedNumber;
}

long int nearestPalindrome(long int number) {
    long int previousPalindrome = number;

    while (!isPalindrome(previousPalindrome)) {
        previousPalindrome--;
    }

    long int nextPalindrome = number;

    while (!isPalindrome(nextPalindrome)) {
        nextPalindrome++;
    }

    if (nextPalindrome - number < number - previousPalindrome) {
        return nextPalindrome;
    }

    return previousPalindrome;
}

int main()
{
    long int n;
    cin >> n;

    if (n < 1 || n > 1e9) {
        cout << -1;
        return 0;
    }

    if (n <= 101) {
        cout << 101;
        return 0;
    }

    cout << nearestPalindrome(n);

    return 0;
}