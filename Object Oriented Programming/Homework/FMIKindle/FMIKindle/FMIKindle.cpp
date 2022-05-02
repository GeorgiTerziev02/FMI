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
	
	bool result = readKindleFromFile(FILE_PATH, kindle);

	if (result)
		std::cout << "Successfully read db!" << std::endl;
	else
		std::cout << "Db not found. Starting with empty db!" << std::endl;

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
			writeKindleToFile(FILE_PATH, kindle);
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
			User user = kindle.getUsersList()[userIndex];

			if (strcmp(command, WRITE_COMMAND) == 0)
			{
				Book book = user.writeBook();
				kindle.addBook(book);
			}
			else if (strcmp(command, COMMENT_COMMAND) == 0) {
				char bookName[INPUT_BUFFER_SIZE];
				std::cout << ">Enter book name: ";
				std::cin.getline(bookName, INPUT_BUFFER_SIZE);

				Book* book = kindle.getBookByName(bookName);
				user.commentBook(book);
			}
			else if (strcmp(command, COMMENTS_COMMAND) == 0) {
				char bookName[INPUT_BUFFER_SIZE];
				std::cout << ">Enter book name: ";
				std::cin.getline(bookName, INPUT_BUFFER_SIZE);

				Book* book = kindle.getBookByName(bookName);
				bool hasRead = user.hasReadBook(book);

				if (hasRead)
				{
					MyList<char*> comments = book->getComments();
					for (size_t i = 0; i < comments.getSize(); i++)
					{
						std::cout << comments[i] << std::endl;
					}
				}
			}
		}
	}

	return 0;
}