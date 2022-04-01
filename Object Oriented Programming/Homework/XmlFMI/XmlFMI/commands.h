#pragma once

#include "system.h"

void printStudents(const System& system);

bool editValue(System& system, const char* inputData);

void swapStudents(Student& firstStudent, Student& secondStudent);

void sortBy(System& system, const char* sortingProperty);