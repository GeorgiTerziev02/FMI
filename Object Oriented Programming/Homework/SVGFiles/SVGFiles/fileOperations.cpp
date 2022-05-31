#include "fileOperations.h"
#include <fstream>
#include "constants.h"
#include "stringHelperFunctions.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"


Rectangle* readRectangleFromString(const char* str) {
	Vector<char*> parts = split(str, ' ');

	int x = 0;
	int y = 0;
	double width = 0;
	double height = 0;

	for (size_t i = 0; i < parts.getSize(); i++)
	{

		delete[] parts[i];
	}

	return new Rectangle(x, y, width, height);
}

Circle* readCircleFromString(const char* str) {
	Vector<char*> parts = split(str, ' ');

	int x = 0;
	int y = 0;
	double radius = 0;

	for (size_t i = 0; i < parts.getSize(); i++)
	{

		delete[] parts[i];
	}

	return new Circle(x, y, radius);
}

Line* readLineFromString(const char* str) {
	Vector<char*> parts = split(str, ' ');

	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;

	for (size_t i = 0; i < parts.getSize(); i++)
	{

		delete[] parts[i];
	}

	return new Line(x1, y1, x2, y2);
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

			if (strcmp(tag, RECTANGLE_TAG) == 0) {
				size_t tagEndIndex = indexOf(fileBuffer, currentIndex, '>');
				char* info = subStr(fileBuffer, indexOfLeftArrow + 1, tagEndIndex - 1);
				shapesCollection->createShape(readRectangleFromString(info));
				delete[] info;
				currentIndex = tagEndIndex;
			}
			else if (strcmp(tag, CIRCLE_TAG) == 0) {
				size_t tagEndIndex = indexOf(fileBuffer, currentIndex, '>');
				char* info = subStr(fileBuffer, indexOfLeftArrow + 1, tagEndIndex - 1);
				shapesCollection->createShape(readCircleFromString(info));
				delete[] info;
				currentIndex = tagEndIndex;
			}
			else if (strcmp(tag, LINE_TAG) == 0) {
				size_t tagEndIndex = indexOf(fileBuffer, currentIndex, '>');
				char* info = subStr(fileBuffer, indexOfLeftArrow + 1, tagEndIndex - 1);
				shapesCollection->createShape(readLineFromString(info));
				delete[] info;
				currentIndex = tagEndIndex;
			}

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