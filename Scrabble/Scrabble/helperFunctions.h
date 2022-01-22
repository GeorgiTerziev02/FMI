#include <string>
using namespace std;

#pragma once
#ifndef SCRABBLE_HELPER_FUNCTIONS
void resetArray(int* arr, int length);
int generateRandomInteger(int minValue, int maxValue);
int* generateRandomLetters(int count);
int* convertWordToIntegerArray(string word);
bool isWordArrayLower(int* arr1, int* arr2);
bool isWordValid(string word);
#endif //SCRABBLE_HELPER_FUNCTIONS
