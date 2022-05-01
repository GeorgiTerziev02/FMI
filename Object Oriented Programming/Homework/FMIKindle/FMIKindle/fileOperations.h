#pragma once
#include "Kindle.h"

bool readKindleFromFile(const char* filePath, Kindle& kindle);

void writeKindleToFile(const char* filePath, const Kindle& kindle);