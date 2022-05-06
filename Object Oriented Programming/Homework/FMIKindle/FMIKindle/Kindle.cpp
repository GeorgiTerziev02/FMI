#include "Kindle.h"
#include <cstring>
#include <iostream>

#pragma warning (disable: 4996)

const MyList<User>* Kindle::getUsersList() const {
	return &users;
}

const MyList<Book>* Kindle::getBooksList() const {
	return &books;
}

size_t Kindle::logIn(char* userName, char* password) const {
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (strcmp(users[i].getUserName(), userName) == 0
			&& strcmp(users[i].getPassword(), password) == 0)
			return i;
	}

	throw "User not found!";
}

size_t Kindle::addUser(char* userName, char* password) {
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (strcmp(users[i].getUserName(), userName) == 0)
			throw "User with this UserName already exists";
	}

	users.add(User(userName, password));
	return users.getSize() - 1;
}

size_t Kindle::addUser(const User& user) {
	users.add(user);
	return users.getSize() - 1;
}

size_t Kindle::addBook(const Book& book) {
	if (getBookByName(book.getName()) != nullptr)
		throw "Book with this name already exists!";

	books.add(book);
	return books.getSize() - 1;
}

Book* Kindle::getBookByName(const char* name) {
	for (size_t i = 0; i < books.getSize(); i++)
	{
		if (strcmp(books[i].getName(), name) == 0)
			return &(books[i]);
	}

	return nullptr;
}

User* Kindle::getUserAtIndex(size_t index) {
	if (index < 0 || index >= users.getSize())
		throw "Invalid index!";

	return &(users[index]);
}

void Kindle::printBooks() const {
	for (size_t i = 0; i < books.getSize(); i++)
		std::cout << i + 1 << ". " << books[i].getName() << " by " << books[i].getAuthorName() << std::endl;
}