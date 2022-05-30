#include <iostream>
#include "constants.h"
#include "fileOperations.h"
#include "ShapesCollection.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

int main() {
	Circle* circle = new Circle(1, 2, 3);
	Line* line = new Line(1, 2, 3, 4);
	Rectangle* rect = new Rectangle(1, 2, 3, 4);

	std::cout << *line << std::endl;
	std::cout << *circle << std::endl;
	std::cout << *rect << std::endl;

	std::cout << "Enter fileName: " << std::endl;
	char fileName[INPUT_BUFFER];
	std::cin.getline(fileName, INPUT_BUFFER);

	ShapesCollection* collection = readFile(fileName);

	while (true)
	{
		std::cout << "Enter command: " << std::endl;
		char input[INPUT_BUFFER];
		std::cin.getline(input, INPUT_BUFFER);
		
		if (strcmp(input, PRINT_COMMAND) == 0)
		{
			collection->printShapes();
		}
		else if (strcmp(input, SAVE_COMMAND) == 0)
		{

		}
		else if (strcmp(input, EXIT_COMMAND) == 0) {
			break;
		}
	}
}