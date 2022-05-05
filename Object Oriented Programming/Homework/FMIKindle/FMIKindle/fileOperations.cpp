#include "fileOperations.h"
#include <fstream>
#include <cstring>

char* readStringFromFile(std::ifstream& file) {
	size_t stringLength;
	file.read((char*)&stringLength, sizeof(size_t));
	char* str = new char[stringLength + 1];
	file.read(str, stringLength);
	str[stringLength] = '\0';

	return str;
}

void writeStringToFile(std::ofstream& file, const char* str) {
	size_t stringLength = strlen(str);
	file.write((const char*)&stringLength, sizeof(size_t));
	file.write(str, stringLength);
}

Book readBookFromFile(std::ifstream& file) {
	Book book;

	char* name = readStringFromFile(file);
	book.setName(name);
	delete[] name;

	char* authorName = readStringFromFile(file);
	book.setAuthorName(authorName);
	delete[] authorName;

	size_t ratingsLength;
	file.read((char*)&ratingsLength, sizeof(size_t));
	for (size_t i = 0; i < ratingsLength; i++)
	{
		char* userName = readStringFromFile(file);
		unsigned short rating;
		file.read((char*)&rating, sizeof(unsigned short));
		Rating ratingObj(userName, rating);
		book.addRating(ratingObj);
		delete[] userName;
	}

	size_t pagesLength;
	file.read((char*)&pagesLength, sizeof(size_t));
	for (size_t i = 0; i < pagesLength; i++)
	{
		char* content = readStringFromFile(file);
		Page page(content);
		book.addPage(page);
		delete[] content;
	}

	size_t commentsLength;
	file.read((char*)&commentsLength, sizeof(size_t));

	for (size_t i = 0; i < commentsLength; i++)
	{
		char* comment = readStringFromFile(file);
		book.addComment(comment);
		delete[] comment;
	}

	return book;
}

// passing the kindle to map the books with the user
User readUserFromFile(std::ifstream& file, Kindle& kindle) {
	char* userName = readStringFromFile(file);
	char* password = readStringFromFile(file);

	User user(userName, password);
	delete[] userName;
	delete[] password;

	size_t readBooksSize;
	file.read((char*)&readBooksSize, sizeof(size_t));

	for (size_t i = 0; i < readBooksSize; i++)
	{
		char* bookName = readStringFromFile(file);
		Book* book = kindle.getBookByName(bookName);
		user.addReadBook(book);
		delete[] bookName;
	}

	size_t wroteBooksSize;
	file.read((char*)&wroteBooksSize, sizeof(size_t));

	for (size_t i = 0; i < wroteBooksSize; i++)
	{
		char* bookName = readStringFromFile(file);
		Book* book = kindle.getBookByName(bookName);
		user.addWroteBook(book);
		delete[] bookName;
	}

	return user;
}

bool readKindleFromFile(const char* filePath, Kindle& kindle) {
	std::ifstream in(filePath, std::ios::binary);

	if (!in.is_open())
		return false;

	size_t booksSize;
	in.read((char*)&booksSize, sizeof(size_t));
	for (size_t i = 0; i < booksSize; i++)
	{
		Book book = readBookFromFile(in);
		kindle.addBook(book);
	}

	size_t usersSize;
	in.read((char*)&usersSize, sizeof(size_t));
	for (size_t i = 0; i < usersSize; i++)
	{
		User user = readUserFromFile(in, kindle);
		kindle.addUser(user);
	}

	return true;
}

void writeUserToFile(std::ofstream& file, const User& user) {
	writeStringToFile(file, user.getUserName());
	writeStringToFile(file, user.getPassword());

	MyList<Book*> readBooks = user.getReadBooks();
	size_t booksSize = readBooks.getSize();
	file.write((const char*)&booksSize, sizeof(size_t));
	for (size_t i = 0; i < booksSize; i++)
	{
		writeStringToFile(file, readBooks[i]->getName());
	}

	MyList<Book*> wroteBooks = user.getWroteBooks();
	size_t wroteBooksSize = wroteBooks.getSize();
	file.write((const char*)&wroteBooksSize, sizeof(size_t));
	for (size_t i = 0; i < wroteBooksSize; i++)
	{
		writeStringToFile(file, wroteBooks[i]->getName());
	}
}

void writeBookToFile(std::ofstream& file, const Book& book) {
	writeStringToFile(file, book.getName());
	writeStringToFile(file, book.getAuthorName());

	MyList<Rating> ratings = book.getRatings();
	size_t ratingsSize = ratings.getSize();
	file.write((const char*)&ratingsSize, sizeof(size_t));
	for (size_t i = 0; i < ratingsSize; i++)
	{
		writeStringToFile(file, ratings[i].getUserName());
		unsigned short rating = ratings[i].getRating();
		file.write((const char*)&rating, sizeof(unsigned short));
	}

	MyList<Page> pages = book.getPages();
	size_t pagesSize = pages.getSize();
	file.write((const char*)&pagesSize, sizeof(size_t));
	for (size_t i = 0; i < pagesSize; i++)
	{
		writeStringToFile(file, pages[i].getContent());
	}

	MyList<char*> comments = book.getComments();
	size_t commentsSize = comments.getSize();
	file.write((const char*)&commentsSize, sizeof(size_t));
	for (size_t i = 0; i < commentsSize; i++)
	{
		writeStringToFile(file, comments[i]);
	}
}


void writeKindleToFile(const char* filePath, const Kindle& kindle) {
	std::ofstream out(filePath, std::ios::binary);

	if (!out.is_open())
		throw "Couldn't open file";

	MyList<Book> books = kindle.getBooksList();
	size_t booksSize = books.getSize();
	out.write((const char*)&booksSize, sizeof(size_t));
	for (size_t i = 0; i < booksSize; i++)
		writeBookToFile(out, books[i]);

	MyList<User> users = kindle.getUsersList();
	size_t usersSize = users.getSize();
	out.write((const char*)&usersSize, sizeof(size_t));
	for (size_t i = 0; i < usersSize; i++)
		writeUserToFile(out, users[i]);

	out.close();
}
