#pragma once
#include "Kindle.h"

Kindle& readKindleFromFile(const char* filePath);

void writeKindleToFile(const char* filePath, const Kindle& kindle);