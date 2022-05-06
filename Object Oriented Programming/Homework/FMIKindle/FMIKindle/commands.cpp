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


Book* getBookByName(Kindle& kindle) {
	char bookName[INPUT_BUFFER_SIZE];
	std::cout << ">Enter book name: ";
	std::cin.getline(bookName, INPUT_BUFFER_SIZE);

	Book* book = kindle.getBookByName(bookName);

	if (book == nullptr)
		throw "Book not found!";

	return book;
}

void readBook(Kindle& kindle, User* user) {
	Book* book = getBookByName(kindle);
	user->readBook(book);
}


void readBookPage(Kindle& kindle, const User* user) {
	Book* book = getBookByName(kindle);
	size_t pageIndex;
	std::cout << "Page index: ";
	std::cin >> pageIndex;
	user->readBookPage(book, pageIndex);
}

void commentBook(Kindle& kindle, User* user) {
	Book* book = getBookByName(kindle);
	user->commentBook(book);
}

void readBookComments(Kindle& kindle, const User* user) {
	Book* book = getBookByName(kindle);
	user->readBookComments(book);
}

void rateBook(Kindle& kindle, const User* user) {
	Book* book = getBookByName(kindle);
	user->rateBook(book);
}

void viewBookRates(Kindle& kindle, const User* user) {
	Book* book = getBookByName(kindle);
	user->viewBookRates(book);
}

void editBook(Kindle& kindle, const User* user) {
	Book* book = getBookByName(kindle);
	user->editBook(book);
}

void editBookRating(Kindle& kindle, const User* user) {
	Book* book = getBookByName(kindle);
	user->editRate(book);
}