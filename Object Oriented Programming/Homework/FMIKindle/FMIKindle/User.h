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

	bool hasReadBook(const Book* book) const;
	bool hasWroteBook(const Book* book) const;

	void addReadBook(Book* book);
	void addWroteBook(Book* book);

	Book writeBook();
	void commentBook(Book* book);
private:
	void copy(const User&);
	void free();
};

