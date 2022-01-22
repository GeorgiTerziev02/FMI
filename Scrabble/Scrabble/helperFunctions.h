/**
*
* Solution to course project # 7
* Introduction to programming course
* Faculty of Mathematics and Informatics of Sofia University
* Winter semester 2021/2022
*
* @author Georgi Terziev
* @idnumber 3MI0600090
* @compiler VC
*
* Header file with helper functions that are needed for implementing the logic of the application
*
*/

#include <string>
using namespace std;

#pragma once
#ifndef SCRABBLE_HELPER_FUNCTIONS
// Set all values in the array to 0
void resetArray(int* arr, int length);
// Generate random integer in the given range
int generateRandomInteger(int minValue, int maxValue);
// Returns array with indexes - alphabet letter
// and values - count of the used letter
int* generateRandomLetters(int count);
// Generate array with indexes - alphabet letter
// and values - count of the used letter
int* convertWordToIntegerArray(string word);
// check if array consists only of the given letters
// the whole alphabet is the size of the arrays, otherwise we should pass the length as well
bool isWordArrayLower(int* arr1, int* arr2);
// Check if all characters in the word are lowercase
bool isWordValid(string word);
#endif //SCRABBLE_HELPER_FUNCTIONS
