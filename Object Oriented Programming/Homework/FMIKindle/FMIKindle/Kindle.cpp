#include "Kindle.h"
#include <cstring>

#pragma warning (disable: 4996)

const MyList<User>& Kindle::getUsersList() const {
	return users;
}

const MyList<Book>& Kindle::getBooksList() const {
	return books;
}

int Kindle::logIn(char* userName, char* password) const {
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (strcmp(users[i].getUserName(), userName) == 0
			&& strcmp(users[i].getPassword(), password) == 0)
		{
			return i;
		}
	}

	return -1;
}

int Kindle::addUser(char* userName, char* password) {
	for (size_t i = 0; i < users.getSize(); i++)
	{
		if (strcmp(users[i].getUserName(), userName) == 0)
		{
			throw "User with this UserName already exists";
		}
	}

	users.add(User(userName, password));
	return users.getSize() - 1;
}

int Kindle::addUser(const User& user) {
	users.add(user);
	return users.getSize() - 1;
}

int Kindle::addBook(const Book& book) {
	books.add(book);
	return books.getSize() - 1;
}