#pragma once
#include "MyList.hpp"
#include "User.h"
#include "Book.h"

class Kindle
{
private:
	MyList<User> users;
	MyList<Book> books;
public:
	Kindle() = default;
	Kindle(const Kindle&);
	Kindle& operator=(const Kindle&);
	~Kindle() = default;

	size_t logIn(char* userName, char* password) const;
	size_t addUser(char* userName, char* password);
	size_t addUser(const User& user);
	size_t addBook(const Book& book);

	const MyList<User>* getUsersList() const;
	const MyList<Book>* getBooksList() const;

	Book* getBookByName(const char* name);
	User* getUserAtIndex(size_t index);

	void printBooks() const;
private:
	void copy(const Kindle&);
	void free();
};

