#include "Book.h"
#include <cstring>

#pragma warning (disable: 4996)

Book::Book() {
	name = new char[1];
	name[0] = '\0';

	authorName = new char[1];
	authorName[0] = '\0';
}

Book::Book(const char* name, const char* authorName, const unsigned short rating) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);

	this->authorName = new char[strlen(authorName) + 1];
	strcpy(this->authorName, authorName);

	this->rating = rating;
}

Book::Book(const Book& other) {
	copy(other);
}

Book::Book(Book&& other) {
	name = other.name;
	authorName = other.authorName;
	rating = other.rating;
	pages = other.pages;
	comments = other.comments;

	other.name = nullptr;
	other.authorName = nullptr;
}

Book& Book::operator=(const Book& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Book& Book::operator=(Book&& other) {
	if (this != &other)
	{
		free();

		name = other.name;
		authorName = other.authorName;
		rating = other.rating;
		pages = other.pages;
		comments = other.comments;

		other.name = nullptr;
		other.authorName = nullptr;
	}

	return *this;
}

Book::~Book() {
	free();
}

void Book::copy(const Book& other) {
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	authorName = new char[strlen(other.authorName) + 1];
	strcpy(authorName, other.authorName);

	rating = other.rating;

	for (size_t i = 0; i < other.pages.getSize(); i++)
	{
		pages.add(other.pages[i]);
	}

	for (size_t i = 0; i < other.comments.getSize(); i++)
	{
		comments.add(other.comments[i]);
	}
}

void Book::free() {
	delete name;
	delete authorName;

	for (size_t i = 0; i < comments.getSize(); i++)
		delete comments[i];
}

const char* Book::getName() const {
	return name;
}

const char* Book::getAuthorName() const {
	return authorName;
}

unsigned short Book::getRating() const {
	return rating;
}

const MyList<Page>& Book::getPages() const {
	return pages;
}

const MyList<char*>& Book::getComments() const {
	return comments;
}

void Book::setName(const char* name) {
	delete this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Book::setAuthorName(const char* authorName) {
	delete this->authorName;
	this->authorName = new char[strlen(authorName) + 1];
	strcpy(this->authorName, authorName);
}

void Book::setRating(const unsigned short rating) {
	this->rating = rating;
}

void Book::addPage(const Page& page) {
	pages.add(page);
}

void Book::addComment(char* comment) {
	comments.add(comment);
}
