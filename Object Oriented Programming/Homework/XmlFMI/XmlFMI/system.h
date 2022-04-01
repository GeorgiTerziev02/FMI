#pragma once
#include "constants.h"
#include "student.h"

struct System {
	int size = 0;
	char fileName[FILE_NAME_SIZE];
	Student students[STUDENTS_MAX_SIZE];
};