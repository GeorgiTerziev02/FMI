#include "fileOperations.h"
#include <fstream>
#include "constants.h"
#include "stringHelperFunctions.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Line.h"
#include "parsers.h"

Rectangle* readRectangleFromString(const char* str) {
	Vector<char*> parts = split(str, ' ');

	int x = 0;
	int y = 0;
	double width = 0;
	double height = 0;
	String fill = "";
	String stroke = "";
	double strokeWidth = 0;

	for (size_t i = 0; i < parts.getSize(); i++)
	{
		// test="123"
		size_t equalsIndex = indexOf(parts[i], 0, '=');
		char* prop = subStr(parts[i], 0, equalsIndex - 1);
		int a = equalsIndex + 2;
		int b = strlen(parts[i]) - 2;
		char* value = subStr(parts[i], equalsIndex + 2, strlen(parts[i]) - 2); // -2 because of "

		if (strcmp(prop, "x") == 0)
			x = intParse(value);
		else if (strcmp(prop, "y") == 0)
			y = intParse(value);
		else if (strcmp(prop, "width") == 0)
			width = doubleParse(value);
		else if (strcmp(prop, "height") == 0)
			height = doubleParse(value);
		else if (strcmp(prop, "stroke") == 0)
			stroke = value;
		else if (strcmp(prop, "stroke-width") == 0)
			strokeWidth = doubleParse(value);
		else if (strcmp(prop, "fill") == 0)
			fill = value;

		delete[] prop;
		delete[] value;
		delete[] parts[i];
	}

	return new Rectangle(x, y, width, height, fill, stroke, strokeWidth);
}

Circle* readCircleFromString(const char* str) {
	Vector<char*> parts = split(str, ' ');

	int x = 0;
	int y = 0;
	double radius = 0;
	String fill = "";
	String stroke = "";
	double strokeWidth = 0;

	for (size_t i = 0; i < parts.getSize(); i++)
	{
		// test="123"
		size_t equalsIndex = indexOf(parts[i], 0, '=');
		char* prop = subStr(parts[i], 0, equalsIndex - 1);
		char* value = subStr(parts[i], equalsIndex + 2, strlen(parts[i]) - 2); // -2 because of "

		if (strcmp(prop, "cx") == 0)
			x = intParse(value);
		else if (strcmp(prop, "cy") == 0)
			y = intParse(value);
		else if (strcmp(prop, "r") == 0)
			radius = doubleParse(value);
		else if (strcmp(prop, "stroke") == 0)
			stroke = value;
		else if (strcmp(prop, "stroke-width") == 0)
			strokeWidth = doubleParse(value);
		else if (strcmp(prop, "fill") == 0)
			fill = value;

		delete[] prop;
		delete[] value;
		delete[] parts[i];
	}

	return new Circle(x, y, radius, fill, stroke, strokeWidth);
}

Line* readLineFromString(const char* str) {
	Vector<char*> parts = split(str, ' ');

	int x1 = 0, x2 = 0;
	int y1 = 0, y2 = 0;
	String stroke = "";
	double strokeWidth = 0;

	for (size_t i = 0; i < parts.getSize(); i++)
	{
		// test="123"
		size_t equalsIndex = indexOf(parts[i], 0, '=');
		char* prop = subStr(parts[i], 0, equalsIndex - 1);
		char* value = subStr(parts[i], equalsIndex + 2, strlen(parts[i]) - 2); // -2 because of "

		if (strcmp(prop, "x1") == 0)
			x1 = intParse(value);
		else if (strcmp(prop, "y1") == 0)
			y1 = intParse(value);
		else if (strcmp(prop, "x2") == 0)
			x2 = doubleParse(value);
		else if (strcmp(prop, "y2") == 0)
			y2 = intParse(value);
		else if (strcmp(prop, "stroke") == 0)
			stroke = value;
		else if (strcmp(prop, "stroke-width") == 0)
			strokeWidth = doubleParse(value);

		delete[] prop;
		delete[] value;
		delete[] parts[i];
	}

	return new Line(x1, y1, x2, y2, stroke, strokeWidth);
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

			if (strcmp(tag, RECTANGLE_TAG) == 0) {
				size_t tagEndIndex = indexOf(fileBuffer, currentIndex, '>');
				char* info = subStr(fileBuffer, indexOfLeftArrow + 1, tagEndIndex - 2); // -2 because of />
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