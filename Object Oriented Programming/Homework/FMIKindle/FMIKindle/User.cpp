#include "User.h"
#include <cstring>

#pragma warning (disable: 4996)

User::User() {
	userName = new char[1];
	userName[0] = '\0';

	password = new char[1];
	password[0] = '\0';
}

User::User(const char* userName, const char* password) {
	this->userName = new char[strlen(userName) + 1];
	strcpy(this->userName, userName);
	this->password = new char[strlen(password) + 1];
	strcpy(this->password, password);
}

User::User(const User& other) {
	copy(other);
}

User& User::operator=(const User& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

User::~User() {
	free();
}

const char* User::getUserName() const {
	return userName;
}

const char* User::getPassword() const {
	return password;
}


const MyList<Book*>& User::getReadBooks() const {
	return readBooks;
}

const MyList<Book*>& User::getWroteBooks() const {
	return wroteBooks;
}

void User::copy(const User& other) {
	userName = new char[strlen(other.userName) + 1];
	strcpy(userName, other.userName);
	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);
}

void User::free() {
	delete userName;
	delete password;

	for (size_t i = 0; i < wroteBooks.getSize(); i++)
		delete wroteBooks[i];

	for (size_t i = 0; i < readBooks.getSize(); i++)
		delete readBooks[i];
}