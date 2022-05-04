#include <iostream>
#include <cstring>
#include "Kindle.h"
#include "constants.h"
#include "commands.h"
#include "fileOperations.h"

int main()
{
	bool isLoggedIn = false;
	User currentUser;

	Kindle kindle;

	bool result = readKindleFromFile(FILE_PATH, kindle);

	if (result)
		std::cout << "Successfully read db!" << std::endl;
	else
		std::cout << "Db not found. Starting with empty db!" << std::endl;

	while (true)
	{
		try
		{
			char input[INPUT_BUFFER_SIZE];
			std::cout << ">";
			std::cin.getline(input, INPUT_BUFFER_SIZE);

			char command[COMMAND_SIZE];
			int index = 0;

			while (input[index] != ' ' && input[index] != '\0')
				command[index] = input[index++];

			command[index++] = '\0';

			if (strcmp(command, QUIT_COMMAND) == 0)
			{
				writeKindleToFile(FILE_PATH, kindle);
				return 0;
			}
			if (!isLoggedIn)
			{
				if (strcmp(command, SIGNUP_COMMAND) == 0)
				{
					int userIndex = signUpUser(kindle);
					isLoggedIn = userIndex >= 0;
					if (isLoggedIn)
						currentUser = kindle.getUsersList()[userIndex];
				}
				else if (strcmp(command, LOGIN_COMMAND) == 0)
				{
					int userIndex = logInUser(kindle);
					isLoggedIn = userIndex >= 0;
					if (isLoggedIn)
						currentUser = kindle.getUsersList()[userIndex];
				}
			}
			else {
				if (strcmp(command, LOGOUT_COMMAND) == 0) {
					isLoggedIn = false;
				}
				else if (strcmp(command, WRITE_COMMAND) == 0)
				{
					Book book = currentUser.writeBook();
					kindle.addBook(book);
				}
				else if (strcmp(command, READ_COMMAND) == 0) {
					readBook(kindle, currentUser);
				}
				else if (strcmp(command, COMMENT_COMMAND) == 0) {
					commentBook(kindle, currentUser);
				}
				else if (strcmp(command, COMMENTS_COMMAND) == 0) {
					readBookComments(kindle, currentUser);
				}
				else if (strcmp(command, RATE_COMMAND) == 0) {
					rateBook(kindle, currentUser);
				}
				else if (strcmp(command, RATES_COMMAND) == 0) {
					viewBookRates(kindle, currentUser);
				}
				else if (strcmp(command, EDIT_COMMAND) == 0) {
					editBook(kindle, currentUser);
				}
			}
		}
		catch (const char* ex)
		{
			std::cout << ex << std::endl;
		}
	}

	return 0;
}