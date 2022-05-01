#include "commands.h"
#include "constants.h"
#include <iostream>

// returns user index in the db
int signUpUser(Kindle& kindle) {
	char userName[INPUT_BUFFER_SIZE], password[INPUT_BUFFER_SIZE];
	std::cout << ">Enter username: ";
	std::cin.getline(userName, INPUT_BUFFER_SIZE);
	std::cout << ">Enter password: ";
	std::cin.getline(password, INPUT_BUFFER_SIZE);

	return kindle.addUser(userName, password);
}

// returns user index in the db
int logInUser(const Kindle& kindle) {
	char userName[INPUT_BUFFER_SIZE], password[INPUT_BUFFER_SIZE];
	std::cout << ">Enter username: ";
	std::cin.getline(userName, INPUT_BUFFER_SIZE);
	std::cout << ">Enter password: ";
	std::cin.getline(password, INPUT_BUFFER_SIZE);

	return kindle.logIn(userName, password);
}