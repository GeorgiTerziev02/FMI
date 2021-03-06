#include "Book.h"
#include <iostream>
#include <cstring>

#pragma warning (disable: 4996)

Book::Book() {
	name = new char[1];
	name[0] = '\0';

	authorName = new char[1];
	authorName[0] = '\0';
}

Book::Book(const char* name, const char* authorName) {
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
	this->authorName = new char[strlen(authorName) + 1];
	strcpy(this->authorName, authorName);
}

Book::Book(const Book& other) {
	copy(other);
}

Book::Book(Book&& other) {
	name = other.name;
	authorName = other.authorName;
	ratings = std::move(other.ratings);
	pages = std::move(other.pages);
	comments = std::move(other.comments);
	rating = calculateRating();

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
		ratings = std::move(other.ratings);
		pages = std::move(other.pages);
		comments = std::move(other.comments);
		rating = calculateRating();

		other.name = nullptr;
		other.authorName = nullptr;
	}

	return *this;
}

Book::~Book() {
	free();
}

void Book::copy(const Book& other) {
	this->name = new char[strlen(other.name) + 1];
	strcpy(this->name, other.name);
	this->authorName = new char[strlen(other.authorName) + 1];
	strcpy(this->authorName, other.authorName);

	ratings = other.ratings;
	pages = other.pages;

	for (size_t i = 0; i < other.comments.getSize(); i++) {
		char* newComment = new char[strlen(other.comments[i]) + 1];
		strcpy(newComment, other.comments[i]);
		comments.add(newComment);
	}

	rating = calculateRating();
}

void Book::free() {
	delete[] name;
	delete[] authorName;

	for (size_t i = 0; i < comments.getSize(); i++)
		delete[] comments[i];

	ratings.clear();
	pages.clear();
	comments.clear();
}

const char* Book::getName() const {
	return name;
}

const char* Book::getAuthorName() const {
	return authorName;
}

double Book::getRating() const {
	return rating;
}

const MyList<Rating>& Book::getRatings() const {
	return ratings;
}

const MyList<Page>& Book::getPages() const {
	return pages;
}

const MyList<char*>& Book::getComments() const {
	return comments;
}

const Page& Book::getPage(size_t index) const {
	if (index < 0 || index >= pages.getSize())
		throw "Invalid index";

	return pages[index];
}

void Book::setName(const char* name) {
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}

void Book::setAuthorName(const char* authorName) {
	delete[] this->authorName;
	this->authorName = new char[strlen(authorName) + 1];
	strcpy(this->authorName, authorName);
}

void Book::addPage(const Page& page) {
	pages.add(page);
}

void Book::addPage(Page&& page) {
	pages.add(page);
}

void Book::addComment(const char* comment) {
	char* newComment = new char[strlen(comment) + 1];
	strcpy(newComment, comment);
	comments.add(newComment);
}

void Book::editPage(const char* newContent, size_t index) {
	if (index < 0 || index >= pages.getSize())
		throw "Invalid index";

	pages[index].setContent(newContent);
}

void Book::addRating(const Rating& rating) {
	if (hasRatingFromUser(rating.getUserName())) 
		throw "There is already rating from this user!";

	ratings.add(rating);
	this->rating = calculateRating();
}

void Book::editRating(const char* userName, const unsigned short r) {
	if (!hasRatingFromUser(userName))
		throw "Rating from user not found!";

	int index = -1;
	for (size_t i = 0; i < ratings.getSize(); i++)
	{
		if (strcmp(ratings[i].getUserName(), userName) == 0) {
			index = i;
			break;
		}
	}

	ratings[index].setRating(r);
	rating = calculateRating();
}


bool Book::hasRatingFromUser(const char* userName) const {
	for (size_t i = 0; i < ratings.getSize(); i++)
	{
		if (strcmp(ratings[i].getUserName(), userName) == 0) 
			return true;
	}

	return false;
}

double Book::calculateRating() const {
	double result = 0;
	int count = ratings.getSize();
	for (size_t i = 0; i < count; i++)
		result += ratings[i].getRating();

	return count == 0 ? 0 : result / count;
}

void Book::printRates() const {
	for (size_t i = 0; i < ratings.getSize(); i++)
		std::cout << ratings[i].getUserName() << " rated " << ratings[i].getRating() << std::endl;
	
}