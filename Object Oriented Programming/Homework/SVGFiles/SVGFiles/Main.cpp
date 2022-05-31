#include <iostream>
#include "constants.h"
#include "fileOperations.h"
#include "ShapesCollection.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

int main() {
	std::cout << "Enter fileName: " << std::endl;
	char fileName[INPUT_BUFFER];
	std::cin.getline(fileName, INPUT_BUFFER);

	ShapesCollection* collection = readFile(fileName);

	while (true)
	{
		std::cout << "Enter command: " << std::endl;
		char input[INPUT_BUFFER];
		std::cin.getline(input, INPUT_BUFFER);
		
		if (strcmp(input, CREATE_COMMAND) == 0)
		{
			collection->createShape(nullptr);
		}
		else if (strcmp(input, PRINT_COMMAND) == 0)
		{
			collection->printShapes();
		}
		else if (strcmp(input, SAVE_COMMAND) == 0)
		{
			saveToFile(fileName, collection);
		}
		else if (strcmp(input, EXIT_COMMAND) == 0) {
			break;
		}
	}
}