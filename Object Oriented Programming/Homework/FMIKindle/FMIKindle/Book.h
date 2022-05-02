#pragma once
#include "MyList.h"
#include "Page.h"
#include "Rating.h"

class Book
{
private:
	char* name;
	char* authorName;
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
	const MyList<Rating>& getRatings() const;
	const MyList<Page>& getPages() const;
	const MyList<char*>& getComments() const;

	void setName(const char* name);
	void setAuthorName(const char* authorName);
	void addPage(const Page& page);

	// template error when const char*...
	void addComment(char* comment);
	void addRating(const Rating& rating);

	bool hasRatingFromUser(const char* userName) const;

private:
	void move(Book&&);
	void copy(const Book&);
	void free();
};

