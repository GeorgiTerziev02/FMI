#include "fileOperations.h"
#include <fstream>
#include "constants.h"
#include "stringHelperFunctions.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"


Rectangle* readRectangleFromString(const char* str) {
	int currentIndex = 0;
	int strLength = strlen(str);

	while (currentIndex < strLength)
	{
		currentIndex++;
	}

	return new Rectangle(1, 1, 1, 1);
}

Circle* readCircleFromString(const char* str) {
	int currentIndex = 0;
	int strLength = strlen(str);

	while (currentIndex < strLength)
	{
		currentIndex++;
	}

	return new Circle(1, 1, 1);
}

Line* readLineFromString(const char* str) {
	int currentIndex = 0;
	int strLength = strlen(str);

	while (currentIndex < strLength)
	{
		currentIndex++;
	}

	return new Line(1, 1, 1, 1);
}

ShapesCollection* readFile(const char* fileName) {

	std::ifstream file(fileName);

	if (!file.is_open())
		throw OPEN_FILE_ERROR_MESSAGE;

	char fileBuffer[FILE_BUFFER_SIZE];
	//will be used as size later
	int length = 0;
	while (!file.eof())
		file.get(fileBuffer[length++]);

	fileBuffer[--length] = '\0';

	file.close();

	ShapesCollection* shapesCollection = new ShapesCollection();
	int currentIndex = 0;
	while (currentIndex < length)
	{

		int indexOfLeftArrow = indexOf(fileBuffer, currentIndex, '<');
		int indexOfFirstSpace = indexOf(fileBuffer, indexOfLeftArrow, ' ');

		if (indexOfLeftArrow != -1 && indexOfFirstSpace != -1)
		{
			char* tag = subStr(fileBuffer, indexOfLeftArrow + 1, indexOfFirstSpace - 1);

			currentIndex = indexOfFirstSpace;

			if (strcmp(tag, RECTANGLE_TAG) == 0)
				shapesCollection->createShape(readRectangleFromString(""));
			else if (strcmp(tag, CIRCLE_TAG) == 0)
				shapesCollection->createShape(readCircleFromString(""));
			else if (strcmp(tag, LINE_TAG) == 0)
				shapesCollection->createShape(readLineFromString(""));

			delete[] tag;
		}

		currentIndex++;
	}

	return shapesCollection;
}

void saveToFile(const char* fileName, const ShapesCollection* collection) {
	std::ofstream file(fileName);

	if (!file.is_open())
		throw OPEN_FILE_ERROR_MESSAGE;

	file << *collection;
	file.close();
}