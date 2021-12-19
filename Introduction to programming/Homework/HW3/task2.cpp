/**
*
* Solution to homework assignment 3
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

int longestDist(const int arr[], const int arrSize) {
    int longestDistance = -1;
    int longestDistanceFirstNumberIndex = -1;

    for (int i = 0; i < arrSize - 1; i++) {
        int currentNumber = arr[i];

        int distance = -1;

        for (int j = i + 1; j < arrSize; j++)
        {
            if (arr[j] == currentNumber) {
                distance = j - i;
                break;
            }
        }

        if (longestDistance < distance) {
            longestDistance = distance;
            longestDistanceFirstNumberIndex = i;
        }
    }

    return longestDistanceFirstNumberIndex;
}

int main()
{
    int arrSize;
    cin >> arrSize;

    int arr[100];

    for (int i = 0; i < arrSize; i++) {
        cin >> arr[i];
    }

    if (arrSize < 2 || arrSize > 100) {
        cout << -2;
        return 0;
    }

    cout << longestDist(arr, arrSize);

    return 0;
}