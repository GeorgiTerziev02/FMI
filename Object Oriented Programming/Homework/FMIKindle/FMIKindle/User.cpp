#include "User.h"
#include "constants.h"
#include <iostream>
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
	if (this != &other) {
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

	readBooks = other.readBooks;
	wroteBooks = other.wroteBooks;
}

void User::free() {
	delete[] userName;
	delete[] password;
}


void User::addReadBook(Book* book) {
	if (!hasReadBook(book))
		readBooks.add(book);
}

void User::addWroteBook(Book* book) {
	if (!hasWroteBook(book))
		wroteBooks.add(book);
}

bool User::hasReadBook(const Book* book) const {
	for (size_t i = 0; i < readBooks.getSize(); i++)
	{
		if (readBooks[i] == book)
			return true;
	}

	return false;
}

bool User::hasWroteBook(const Book* book) const {
	for (size_t i = 0; i < wroteBooks.getSize(); i++)
	{
		if (wroteBooks[i] == book)
			return true;
	}

	return false;
}

void User::readBook(Book* book) {
	MyList<Page> pages = book->getPages();

	int index = 0;
	std::cout << "n - next page" << std::endl;
	std::cout << "p - prev page" << std::endl;
	std::cout << "q - quit" << std::endl;

	bool loop = true;
	while (loop)
	{
		char input;
		std::cout << pages[index].getContent() << std::endl;
		std::cout << ">";
		std::cin >> input;

		switch (input)
		{
		case 'n': {
			if (index < pages.getSize() - 1) index++;
		}; break;
		case 'p': {
			if (index > 0) index--;
		}; break;
		case 'q': {
			loop = false;
		}; break;
		}
	}

	addReadBook(book);
}

Book User::writeBook() {
	char bookName[INPUT_BUFFER_SIZE];
	std::cout << ">Enter book name: ";
	std::cin.getline(bookName, INPUT_BUFFER_SIZE);

	Book book(bookName, userName);

	while (true)
	{
		char pageContent[PAGE_BUFFER_SIZE];
		std::cout << ">Enter page content or enter q to stop: ";
		std::cin.getline(pageContent, PAGE_BUFFER_SIZE);

		if (strcmp(pageContent, "q") == 0)
			break;

		book.addPage(Page(pageContent));
	}

	return book;
}


void User::readBookPage(Book* book, size_t pageIndex) const {
	Page page = book->getPage(pageIndex);
	std::cout << page.getContent() << std::endl;
}

void User::editBook(Book* book) const {
	if (!hasWroteBook(book))
		throw "User is not the author of this book!";

	char command[INPUT_BUFFER_SIZE];
	std::cout << "Will you change book name?(yes/no)" << std::endl;
	std::cin.getline(command, INPUT_BUFFER_SIZE);

	if (strcmp(command, "yes") == 0) {
		char newBookName[INPUT_BUFFER_SIZE];
		std::cout << ">Enter new book name: ";
		std::cin.getline(newBookName, INPUT_BUFFER_SIZE);

		book->setName(newBookName);
	}

	while (true)
	{		
		int page;
		std::cout << "Which page you want to edit?(enter -1 to quit)" << std::endl;
		std::cin >> page;
		std::cin.clear();
		std::cin.sync();
		std::cin.ignore();

		if (page == -1)
			break;

		char pageContent[PAGE_BUFFER_SIZE];
		std::cout << "Enter new content" << std::endl;
		std::cout << ">";
		std::cin.getline(pageContent, PAGE_BUFFER_SIZE);

		book->editPage(pageContent, page);
	}
}

void User::commentBook(Book* book) const {
	if (!hasReadBook(book))
		throw "User have not read the book!";

	char comment[INPUT_BUFFER_SIZE];
	std::cout << ">Enter comment: ";
	std::cin.getline(comment, INPUT_BUFFER_SIZE);

	book->addComment(comment);
}


void User::readBookComments(const Book* book) const {
	MyList<char*> comments = book->getComments();
	for (size_t i = 0; i < comments.getSize(); i++)
		std::cout << comments[i] << std::endl;
}


void User::rateBook(Book* book) const {
	if (hasWroteBook(book))
		throw "User cannot rate a book he wrote!";

	if (!hasReadBook(book))
		throw "User cannot rate a book he hasn't read!";

	unsigned short rating = -1;
	while (rating < 0 || rating > 10)
	{
		std::cout << ">Enter book rating: ";
		std::cin >> rating;
	}

	Rating ratingObj(getUserName(), rating);

	book->addRating(ratingObj);
}

void User::editRate(Book* book) const {
	if (hasWroteBook(book))
		throw "User cannot rate a book he wrote!";

	if (!hasReadBook(book))
		throw "User cannot rate a book he hasn't read!";

	unsigned short rating = -1;
	while (rating < 0 || rating > 10)
	{
		std::cout << ">Enter new book rating: ";
		std::cin >> rating;
	}

	book->editRating(userName, rating);
}

void User::viewBookRates(Book* book) const {
	MyList<Rating> ratings = book->getRatings();

	for (size_t i = 0; i < ratings.getSize(); i++)
		std::cout << ratings[i].getUserName() << " - " << ratings[i].getRating() << std::endl;
}