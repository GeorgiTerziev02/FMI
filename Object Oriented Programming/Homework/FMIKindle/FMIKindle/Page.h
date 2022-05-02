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
	Page& operator=(Page&& other) noexcept;
	~Page();

	const char* getContent() const;
	void setContent(const char* content);
private:
	void copy(const Page&);
	void free();
};

