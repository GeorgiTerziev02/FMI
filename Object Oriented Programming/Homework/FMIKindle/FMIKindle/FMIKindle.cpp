#include <iostream>
#include <cstring>
#include "Kindle.h"
#include "constants.h"
#include "commands.h"
#include "fileOperations.h"

int main()
{
	bool isLoggedIn = false;
	size_t userIndex = -1;
	Kindle kindle;
	while (true)
	{
		char input[INPUT_BUFFER_SIZE];
		std::cout << ">";
		std::cin.getline(input, INPUT_BUFFER_SIZE);

		char command[COMMAND_SIZE];
		int index = 0;

		while (input[index] != ' ' && input[index] != '\0')
		{
			command[index] = input[index++];
		}
		command[index++] = '\0';

		if (strcmp(command, QUIT_COMMAND) == 0)
		{
			writeKindleToFile("kindle.bin", kindle);
			return 0;
		}
		if (!isLoggedIn)
		{
			if (strcmp(command, SIGNUP_COMMAND) == 0)
			{
				userIndex = signUpUser(kindle);
				isLoggedIn = userIndex >= 0;
			}
			else if (strcmp(command, LOGIN_COMMAND) == 0) 
			{
				userIndex = logInUser(kindle);
				isLoggedIn = userIndex >= 0;
			}
		}
		else {

		}
	}

	return 0;
}