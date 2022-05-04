#pragma once
#include "MyList.h"
#include "Page.h"
#include "Rating.h"

class Book
{
private:
	char* name;
	char* authorName;
	double rating;
	MyList<Rating> ratings;
	MyList<Page> pages;
	MyList<char*> comments;
public:
	Book();
	Book(const char* name, const char* authorName);
	Book(const Book&);
	Book(Book&&);
	Book& operator=(const Book&);
	Book& operator=(Book&&);
	~Book();

	const char* getName() const;
	const char* getAuthorName() const;
	double getRating() const;
	const MyList<Rating>& getRatings() const;
	const MyList<Page>& getPages() const;
	const MyList<char*>& getComments() const;
	const Page& getPage(size_t index) const;

	void setName(const char* name);
	void setAuthorName(const char* authorName);
	void addPage(const Page& page);
	void editPage(const char* newContent, size_t index);

	// template error when const char*...
	void addComment(char* comment);
	void addRating(const Rating& rating);
	void editRating(const Rating& newRating);

	bool hasRatingFromUser(const char* userName) const;

private:
	double calculateRating() const;
	void copy(const Book&);
	void free();
};

