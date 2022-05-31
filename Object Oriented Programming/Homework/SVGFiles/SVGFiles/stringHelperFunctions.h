#pragma once
#include "Vector.hpp"

int indexOf(const char* str1, const int& fromIndex, const char& character);

char* subStr(const char* str, const int& startIndex, const int& endIndex);

Vector<char*> split(const char* str, char separator);