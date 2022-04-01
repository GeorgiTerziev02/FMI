#pragma once
#include "constants.h"

struct Student {
	char name[FIELD_MAX_SIZE];
	int fn;
	int age;
	bool gender;
	char email[FIELD_MAX_SIZE];
	double grade;
};