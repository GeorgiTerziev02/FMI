#pragma once
#include <iostream>

class String
{
private:
	char* str;
	size_t size;
public:
	String();
	String(const char*);
	String(const String&);
	String& operator=(const String&);
	~String();

	void setName(const char*);
	const char* c_str() const;
	size_t getSize() const;

	void concat(const String&);

	String& operator+=(const String&);
	friend std::ostream& operator<<(std::ostream&, const String&);
	friend std::istream& operator>>(std::istream&, String&);
private:
	void copy(const String&);
	void free();
};