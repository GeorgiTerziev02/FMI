#include "Rating.h"
#include <cstring>

#pragma warning (disable: 4996)

Rating::Rating() {
	userName = new char[1];
	userName[0] = '\0';
	
	rating = 0;
}

Rating::Rating(const char* userName, const unsigned short rating) {
	this->userName = new char[strlen(userName) + 1];
	strcpy(this->userName, userName);

	setRating(rating);
}

Rating::Rating(const Rating& other) {
	copy(other);
}

Rating& Rating::operator=(const Rating& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Rating::~Rating() {
	free();
}

const char* Rating::getUserName() const {
	return userName;
}

unsigned short Rating::getRating() const {
	return rating;
}

void Rating::setRating(const unsigned short rating) {
	if (rating < 0 || rating > 10)
	{
		throw "Invalid rating";
	}

	this->rating = rating;
}

void Rating::copy(const Rating& other) {
	userName = new char[strlen(other.userName) + 1];
	strcpy(userName, other.userName);

	rating = other.rating;
}

void Rating::free() {
	delete userName;
}