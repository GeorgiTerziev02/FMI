#include <iostream>
#include <cstring>
#include "Kindle.h"
#include "constants.h"
#include "commands.h"
#include "fileOperations.h"

int main()
{
	bool isLoggedIn = false;
	User* currentUser = nullptr;

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
			char command[INPUT_BUFFER_SIZE];
			std::cout << ">";
			std::cin.getline(command, INPUT_BUFFER_SIZE);

			if (strcmp(command, QUIT_COMMAND) == 0)
			{
				writeKindleToFile(FILE_PATH, kindle);
				return 0;
			}
			else if (!isLoggedIn)
			{
				if (strcmp(command, SIGNUP_COMMAND) == 0)
				{
					int userIndex = signUpUser(kindle);
					isLoggedIn = userIndex >= 0;
					if (isLoggedIn) {
						currentUser = kindle.getUserAtIndex(userIndex);
						std::cout << "Successfully logged in!" << std::endl;
					}
				}
				else if (strcmp(command, LOGIN_COMMAND) == 0)
				{
					int userIndex = logInUser(kindle);
					isLoggedIn = userIndex >= 0;
					if (isLoggedIn) {
						currentUser = kindle.getUserAtIndex(userIndex);
						std::cout << "Successfully logged in!" << std::endl;
					}
					else {
						std::cout << "User not found!" << std::endl;
					}
				}
			}
			else {
				if (strcmp(command, LOGOUT_COMMAND) == 0) {
					isLoggedIn = false;
					std::cout << "You are logged out!" << std::endl;
				}
				else if (strcmp(command, WRITE_COMMAND) == 0)
				{
					Book book = currentUser->writeBook();
					kindle.addBook(book);
					// wrote book is added to user only if book is added successfully to kindle
					Book* kindleBook = kindle.getBookByName(book.getName());
					currentUser->addWroteBook(kindleBook);
				}
				else if (strcmp(command, READ_COMMAND) == 0) {
					readBook(kindle, currentUser);
				}
				else if (strcmp(command, READ_PAGE_COMMAND) == 0) {
					readBookPage(kindle, currentUser);
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
				else if (strcmp(command, EDIT_RATING_COMMAND) == 0) {
					editBookRating(kindle, currentUser);
				}
				else if (strcmp(command, VIEW_COMMAND) == 0) {
					viewBooks(kindle);
				}
				else if (strcmp(command, ADD_PAGE_COMMAND) == 0) {
					addPage(kindle, currentUser);
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