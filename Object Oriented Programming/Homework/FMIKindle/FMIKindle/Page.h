#pragma once
class Page
{
private:
	char* content;

public:
	Page();
	Page(const char* content);
	Page(const Page&);
	Page& operator=(const Page&);
	Page& operator=(Page&& other);
	~Page();

	const char* getContent() const;
private:
	void copy(const Page&);
	void free();
};

