#pragma once
#include "Book.h"

class User
{
private:
	char* userName;
	char* password;
	MyList<Book*> readBooks;
	MyList<Book*> wroteBooks;

public:
	User();
	User(const char*, const char*);
	User(const User&);
	User& operator=(const User&);
	~User();

	const char* getUserName() const;
	const char* getPassword() const;
	const MyList<Book*>& getReadBooks() const;
	const MyList<Book*>& getWroteBooks() const;

private:
	void copy(const User&);
	void free();
};

