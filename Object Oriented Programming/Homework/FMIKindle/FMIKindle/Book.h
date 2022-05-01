#pragma once
#include "MyList.h"
#include "Page.h"

class Book
{
private:
	char* name;
	char* authorName;
	unsigned short rating;
	MyList<Page> pages;
	MyList<char*> comments;
public:
	Book();
	Book(const char* name, const char* authorName, const unsigned short rating);
	Book(const Book&);
	Book& operator=(const Book&);
	~Book();

	const char* getName() const;
	const char* getAuthorName() const;
	unsigned short getRating() const;
	const MyList<Page>& getPages() const;
	const MyList<char*>& getComments() const;

	void setName(const char* name);
	void setAuthorName(const char* authorName);
	void setRating(const unsigned short rating);
	void addPage(const Page& page);
	// template error when const char*...
	void addComment(char* comment);

private:
	void copy(const Book&);
	void free();
};

