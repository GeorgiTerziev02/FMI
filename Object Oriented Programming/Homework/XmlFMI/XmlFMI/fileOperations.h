#pragma once

#include <fstream>
#include "system.h"
#include "student.h"

bool readSystem(System& system);

void writeStudentToFile(const Student& student, std::ofstream& file);

bool writeSystem(const System& system);