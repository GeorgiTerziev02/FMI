#include "String.h"
#include <cstring>
#pragma warning (disable: 4996)

void String::copy(const String& other)
{
	size = other.size;
	str = new char[size + 1];
	strcpy(str, other.str);
}

void String::free()
{
	delete[] str;
}

String::String()
{
	size = 0;
	str = new char[1];
	str[0] = '\0';
}
String::String(const char* data)
{
	size = strlen(data);
	str = new char[size + 1];
	strcpy(str, data);
}
String::String(const String& other)
{
	copy(other);
}
String& String::operator=(const String& other)
{
	if (this != &other)
	{
		free();
		copy(other);
	}
	return *this;
}
String::~String()
{
	free();
}

size_t String::getSize() const
{
	return size;
}
const char* String::c_str() const
{
	return str;
}
void String::setName(const char* data)
{
	delete[] str;
	size = strlen(data);
	str = new char[size + 1];
	strcpy(str, data);
}
void String::concat(const String& other)
{
	size = size + other.size;
	char* temp = new char[size + 1];
	strcpy(temp, str);
	strcat(temp, other.str);

	delete[] str;
	str = temp;
}

String& String::operator+=(const String& other)
{
	concat(other.str);
	return *this;
}

std::ostream& operator<<(std::ostream& out, const String& obj)
{
	out << obj.str;
	return out;
}

std::istream& operator>>(std::istream& in, String& obj)
{
	char buffer[1024];
	in >> buffer;

	obj.free();
	obj.size = strlen(buffer);
	obj.str = new char[obj.size + 1];
	strcpy(obj.str, buffer);

	return in;
}

String operator+(const String& lhs, const String& rhs)
{
	String temp(lhs);
	temp += rhs;
	return temp;
}