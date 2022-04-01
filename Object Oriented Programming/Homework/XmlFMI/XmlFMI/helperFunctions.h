#pragma once
#include "constants.h"
#include "system.h";

void printInputCharacter();

void printOperationResultMessage(bool result);

void printDataErrorMessage();

double myPow(double number, int degree);

bool checkRequiredFields(bool validationArray[FIELDS_COUNT]);

char* getTag(const char* buffer, int& startIndex);

int getStudentIndexByFn(const System& system, const int& fn);

void printStudent(const Student& student);