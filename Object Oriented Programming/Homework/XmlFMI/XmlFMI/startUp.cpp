#include "startUp.h"
#include "system.h"
#include "constants.h"
#include "helperFunctions.h"
#include "stringHelperFunctions.h"
#include "commands.h"
#include "fileOperations.h"
#include <iostream>

using namespace std;

void startMenu(System& system) {
	while (true)
	{
		char input[INPUT_BUFFER_SIZE];
		printInputCharacter();
		cin.getline(input, INPUT_BUFFER_SIZE);

		int index = indexOf(input, 0, ' ');
		int inputLength = strLength(input);
		char* command = subStr(input, 0, index == -1 ? inputLength - 1 : index - 1);

		if (strCmp(command, EDIT_COMMAND) == 0)
		{
			char* inputData = subStr(input, index + 1, inputLength - 1);
			bool result = editValue(system, inputData);
			if (!result) printDataErrorMessage();
			else printOperationResultMessage(result);
			delete[] inputData;
		}
		else if (strCmp(command, SORT_COMMAND) == 0)
		{
			char* sortingProperty = subStr(input, index + 1, inputLength - 1);
			sortBy(system, sortingProperty);
			printOperationResultMessage(true);
			delete[] sortingProperty;
		}
		else if (strCmp(command, PRINT_COMMAND) == 0)
		{
			printStudents(system);
		}
		else if (strCmp(command, SAVE_COMMAND) == 0)
		{
			bool result = writeSystem(system);

			printOperationResultMessage(result);
			if (result) {
				delete[] command;
				return;
			}
		}

		delete[] command;
	}
}

void run() {
	System system;
	cout << "Enter a file path:" << endl;
	printInputCharacter();
	cin.getline(system.fileName, FILE_NAME_SIZE);

	bool success = readSystem(system);
	if (!success) return;
	cout << "File loaded successfully!" << endl;

	startMenu(system);
}