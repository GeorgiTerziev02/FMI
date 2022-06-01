#include <iostream>
#include "constants.h"
#include "fileOperations.h"
#include "ShapesCollection.h"
#include "Circle.h"
#include "Line.h"
#include "Rectangle.h"

void clearInputBuffer() {
	std::cin.clear();
	std::cin.sync();
	std::cin.ignore();
}

int main() {
	std::cout << "Enter fileName: " << std::endl;
	char fileName[INPUT_BUFFER];
	std::cin.getline(fileName, INPUT_BUFFER);

	ShapesCollection* collection = readFile(fileName);

	while (true)
	{
		try
		{
			std::cout << "Enter command: " << std::endl;
			char input[INPUT_BUFFER];
			std::cin.getline(input, INPUT_BUFFER);

			if (strcmp(input, CREATE_COMMAND) == 0) {
				std::cout << "Enter type: " << std::endl;
				char type[INPUT_BUFFER];
				std::cin.getline(type, INPUT_BUFFER);

				Shape* shape = nullptr;
				if (strcmp(type, "rectangle") == 0)
				{
					int x = 0, y = 0;
					std::cout << "Enter x:" << std::endl;
					std::cin >> x;
					std::cout << "Enter y:" << std::endl;
					std::cin >> y;

					double width = 0, height = 0;
					std::cout << "Enter width:" << std::endl;
					std::cin >> width;
					std::cout << "Enter height:" << std::endl;
					std::cin >> height;

					String fill;
					std::cout << "Enter fill:" << std::endl;
					std::cin >> fill;
					String stroke;
					std::cout << "Enter stroke:" << std::endl;
					std::cin >> stroke;
					double strokeWidth = 0;
					std::cout << "Enter stroke width:" << std::endl;
					std::cin >> strokeWidth;

					shape = new Rectangle(x, y, width, height, fill, stroke, strokeWidth);
				}
				else if (strcmp(type, "circle") == 0)
				{
					int x = 0, y = 0;
					std::cout << "Enter x:" << std::endl;
					std::cin >> x;
					std::cout << "Enter y:" << std::endl;
					std::cin >> y;

					double radius = 0;
					std::cout << "Enter radius:" << std::endl;
					std::cin >> radius;

					String fill;
					std::cout << "Enter fill:" << std::endl;
					std::cin >> fill;
					String stroke;
					std::cout << "Enter stroke:" << std::endl;
					std::cin >> stroke;
					double strokeWidth = 0;
					std::cout << "Enter stroke width:" << std::endl;
					std::cin >> strokeWidth;

					shape = new Circle(x, y, radius, fill, stroke, strokeWidth);
				}
				else if (strcmp(type, "line") == 0)
				{
					int x1 = 0, y1 = 0, x2 = 0, y2 = 0;
					std::cout << "Enter x1:" << std::endl;
					std::cin >> x1;
					std::cout << "Enter y1:" << std::endl;
					std::cin >> y1;
					std::cout << "Enter x2:" << std::endl;
					std::cin >> x2;
					std::cout << "Enter y2:" << std::endl;
					std::cin >> y2;

					String stroke;
					std::cout << "Enter stroke:" << std::endl;
					std::cin >> stroke;
					double strokeWidth = 0;
					std::cout << "Enter stroke width:" << std::endl;
					std::cin >> strokeWidth;

					shape = new Line(x1, y1, x2, y2, stroke, strokeWidth);
				}

				if (shape != nullptr) {
					collection->createShape(shape);
					delete shape;
				}
			}
			else if (strcmp(input, WITHIN_COMMAND) == 0) {
				std::cout << "Enter type:" << std::endl;
				char type[INPUT_BUFFER];
				std::cin.getline(type, INPUT_BUFFER);

				Shape* shape = nullptr;
				if (strcmp(type, "rectangle") == 0)
				{
					int x = 0, y = 0;
					std::cout << "Enter x:" << std::endl;
					std::cin >> x;
					std::cout << "Enter y:" << std::endl;
					std::cin >> y;

					double width = 0, height = 0;
					std::cout << "Enter width:" << std::endl;
					std::cin >> width;
					std::cout << "Enter height:" << std::endl;
					std::cin >> height;

					shape = new Rectangle(x, y, width, height, "", "", 0);
				}
				else if (strcmp(type, "circle") == 0)
				{
					int x = 0, y = 0;
					std::cout << "Enter x:" << std::endl;
					std::cin >> x;
					std::cout << "Enter y:" << std::endl;
					std::cin >> y;

					double radius = 0;
					std::cout << "Enter radius:" << std::endl;
					std::cin >> radius;
					shape = new Circle(x, y, radius, "", "", 0);
				}

				if (shape != nullptr) {
					collection->printWithin(shape);
					delete shape;
				}
			}
			else if (strcmp(input, ERASE_COMMAND) == 0) {
				size_t index;
				std::cout << "Enter index:" << std::endl;
				std::cin >> index;

				collection->eraseShape(index - 1);
			}
			else if (strcmp(input, TRANSLATE_COMMAND) == 0) {
				int x = 0, y = 0, index = -1;
				std::cout << "Vertical:" << std::endl;
				std::cin >> x;
				std::cout << "Horizontal:" << std::endl;
				std::cin >> y;
				std::cout << "Index (enter -1 for all):" << std::endl;
				std::cin >> index;

				collection->translate(x, y, index);
			}
			else if (strcmp(input, POINTIN_COMMAND) == 0) {
				int x = 0, y = 0;
				std::cout << "Enter x:" << std::endl;
				std::cin >> x;
				std::cout << "Enter y:" << std::endl;
				std::cin >> y;

				collection->printContainingPoint(x, y);
			}
			else if (strcmp(input, AREAS_COMMAND) == 0) {
				collection->printAreas();
			}
			else if (strcmp(input, PERS_COMMAND) == 0) {
				collection->printPerimeters();
			}
			else if (strcmp(input, PRINT_COMMAND) == 0) {
				collection->printShapes();
			}
			else if (strcmp(input, SAVE_COMMAND) == 0) {
				saveToFile(fileName, collection);
			}
			else if (strcmp(input, EXIT_COMMAND) == 0) {
				break;
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}
}