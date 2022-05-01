#pragma once
#include "MyList.h"
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

	int logIn(char* userName, char* password) const;
	int addUser(char* userName, char* password);
	int addBook(const Book& book);

	const MyList<User>& getUsersList() const;
	const MyList<Book>& getBooksList() const;
private:
	void copy(const Kindle&);
	void free();
};

