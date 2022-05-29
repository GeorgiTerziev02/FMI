#pragma once
#include "ShapesCollection.h"

ShapesCollection* readFile(const char* fileName);

void saveToFile(const char* fileName, const ShapesCollection* collection);