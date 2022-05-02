#include "Page.h"
#include <cstring>

#pragma warning (disable: 4996)

Page::Page() {
	content = new char[1];
	content[0] = '\0';
}

Page::Page(const char* content) {
	setContent(content);
}

Page::Page(const Page& other) {
	copy(other);
}

Page& Page::operator=(const Page& other) {
	if (this != &other)
	{
		free();
		copy(other);
	}

	return *this;
}

Page& Page::operator=(Page&& other) noexcept {
	if (this != &other) {
		free();

		content = other.content;
		other.content = nullptr;
	}

	return *this;
}

Page::~Page() {
	free();
}

void Page::copy(const Page& other) {
	content = new char[strlen(other.content) + 1];
	strcpy(content, other.content);
}

void Page::free() {
	delete content;
}

const char* Page::getContent() const {
	return content;
}

void Page::setContent(const char* content) {
	delete this->content;
	this->content = new char[strlen(content) + 1];
	strcpy(this->content, content);
}
