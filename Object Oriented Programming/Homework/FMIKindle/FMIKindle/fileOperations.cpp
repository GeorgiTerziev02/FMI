#include "fileOperations.h"
#include <fstream>
#include <cstring>

char* readStringFromFile(std::ifstream& file) {
	size_t stringLength;
	file.read((char*)&stringLength, sizeof(stringLength));
	char* str = new char[stringLength + 1];
	file.read(str, stringLength);
	str[stringLength] = '\0';

	return str;
}

Book& readBookFromFile(std::ifstream& file) {
	Book book;

	//size_t nameLength;
	//file.read((char*)&nameLength, sizeof(nameLength));
	//char* name = new char[nameLength + 1];
	//file.read(name, nameLength);
	//name[nameLength] = '\0';

	char* name = readStringFromFile(file);
	book.setName(name);
	delete name;

	//size_t authorNameLength;
	//file.read((char*)&authorNameLength, sizeof(authorNameLength));
	//char* authorName = new char[authorNameLength + 1];
	//file.read(authorName, authorNameLength);
	//authorName[authorNameLength] = '\0';

	char* authorName = readStringFromFile(file);
	book.setAuthorName(authorName);
	delete authorName;

	unsigned short rating;
	file.read((char*)&rating, sizeof(rating));
	book.setRating(rating);

	size_t pagesLength;
	file.read((char*)&pagesLength, sizeof(pagesLength));
	for (size_t i = 0; i < pagesLength; i++)
	{
		//size_t contentLength;
		//file.read((char*)&contentLength, sizeof(contentLength));
		//char* content = new char[contentLength + 1];
		//file.read(content, contentLength);
		//content[contentLength] = '\0';

		char* content = readStringFromFile(file);
		book.addPage(Page(content));
		delete content;
	}

	size_t commentsLength;
	file.read((char*)&commentsLength, sizeof(commentsLength));

	for (size_t i = 0; i < commentsLength; i++)
	{
		//size_t commentLength;
		//file.read((char*)&commentLength, sizeof(commentLength));
		//char* comment = new char[commentLength + 1];
		//file.read(comment, commentLength);
		//comment[commentLength] = '\0';

		char* comment = readStringFromFile(file);
		book.addComment(comment);
		delete comment;
	}

	return book;
}

// passing the kindle to map the books with the user
User readUserFromFile(std::ifstream& file, const Kindle& kindle) {
	char* userName = readStringFromFile(file);
	char* password = readStringFromFile(file);

	User user(userName, password);
	delete userName;
	delete password;

	return user;
	//MyList<Book*> readBooks = user.getReadBooks();
	//size_t booksSize = readBooks.getSize();
	//file.write((const char*)&booksSize, sizeof(size_t));
	//for (size_t i = 0; i < booksSize; i++)
	//{
	//	size_t bookNameLength = strlen(readBooks[i]->getName());
	//	file.write((const char*)&bookNameLength, sizeof(bookNameLength));
	//	file.write(readBooks[i]->getName(), bookNameLength);
	//}

	//MyList<Book*> wroteBooks = user.getWroteBooks();
	//size_t wroteBooksSize = wroteBooks.getSize();
	//file.write((const char*)&wroteBooksSize, sizeof(size_t));
	//for (size_t i = 0; i < wroteBooksSize; i++)
	//{
	//	size_t bookNameLength = strlen(wroteBooks[i]->getName());
	//	file.write((const char*)&bookNameLength, sizeof(bookNameLength));
	//	file.write(wroteBooks[i]->getName(), bookNameLength);
	//}
}

bool readKindleFromFile(const char* filePath, Kindle& kindle) {
	std::ifstream in(filePath, std::ios::binary);

	if (!in.is_open())
	{
		return false;
	}

	size_t booksSize;
	in.read((char*)&booksSize, sizeof(booksSize));
	for (size_t i = 0; i < booksSize; i++)
	{
		kindle.addBook(readBookFromFile(in));
	}

	size_t usersSize = 0;
	in.read((char*)&usersSize, sizeof(usersSize));
	for (size_t i = 0; i < usersSize; i++)
	{
		// todo: get user and map him to his books
		User user = readUserFromFile(in, kindle);
		kindle.addUser(user);
	}

	return true;
}

void writeStringToFile(std::ofstream& file, const char* str) {
	size_t stringLength = strlen(str);
	file.write((const char*)&stringLength, sizeof(stringLength));
	file.write(str, stringLength);
}

void writeUserToFile(std::ofstream& file, const User& user) {
	//size_t userNameLength = strlen(user.getUserName());
	//file.write((const char*)&userNameLength, sizeof(userNameLength));
	//file.write(user.getUserName(), userNameLength);
	writeStringToFile(file, user.getUserName());

	//size_t passwordLength = strlen(user.getPassword());
	//file.write((const char*)&passwordLength, sizeof(passwordLength));
	//file.write(user.getPassword(), passwordLength);
	writeStringToFile(file, user.getPassword());

	MyList<Book*> readBooks = user.getReadBooks();
	size_t booksSize = readBooks.getSize();
	file.write((const char*)&booksSize, sizeof(size_t));
	for (size_t i = 0; i < booksSize; i++)
	{
		//size_t bookNameLength = strlen(readBooks[i]->getName());
		//file.write((const char*)&bookNameLength, sizeof(bookNameLength));
		//file.write(readBooks[i]->getName(), bookNameLength);
		writeStringToFile(file, readBooks[i]->getName());
	}

	MyList<Book*> wroteBooks = user.getWroteBooks();
	size_t wroteBooksSize = wroteBooks.getSize();
	file.write((const char*)&wroteBooksSize, sizeof(size_t));
	for (size_t i = 0; i < wroteBooksSize; i++)
	{
		//size_t bookNameLength = strlen(wroteBooks[i]->getName());
		//file.write((const char*)&bookNameLength, sizeof(bookNameLength));
		//file.write(wroteBooks[i]->getName(), bookNameLength);
		writeStringToFile(file, wroteBooks[i]->getName());
	}
}

void writeBookToFile(std::ofstream& file, const Book& book) {
	size_t nameLength = strlen(book.getName());
	file.write((const char*)&nameLength, sizeof(nameLength));
	file.write(book.getName(), nameLength);

	size_t authorNameLength = strlen(book.getAuthorName());
	file.write((const char*)&authorNameLength, sizeof(authorNameLength));
	file.write(book.getAuthorName(), authorNameLength);

	unsigned short rating = book.getRating();
	file.write((const char*)&rating, sizeof(book.getRating()));

	MyList<Page> pages = book.getPages();
	size_t pagesSize = pages.getSize();
	file.write((const char*)&pagesSize, sizeof(size_t));
	for (size_t i = 0; i < pagesSize; i++)
	{
		size_t contentLength = strlen(pages[i].getContent());
		file.write((const char*)&contentLength, sizeof(contentLength));
		file.write(pages[i].getContent(), contentLength);
	}

	MyList<char*> comments = book.getComments();
	size_t commentsSize = comments.getSize();
	file.write((const char*)&commentsSize, sizeof(size_t));
	for (size_t i = 0; i < commentsSize; i++)
	{
		size_t commentLength = strlen(comments[i]);
		file.write((const char*)&commentLength, sizeof(commentLength));
		file.write(comments[i], commentLength);
	}
}


void writeKindleToFile(const char* filePath, const Kindle& kindle) {
	std::ofstream out(filePath, std::ios::binary);

	if (!out.is_open())
	{
		throw "Couldn't open file";
	}

	MyList<Book> books = kindle.getBooksList();
	size_t booksSize = books.getSize();
	out.write((const char*)&booksSize, sizeof(size_t));
	for (size_t i = 0; i < booksSize; i++)
	{
		writeBookToFile(out, books[i]);
	}

	MyList<User> users = kindle.getUsersList();
	size_t usersSize = users.getSize();
	out.write((const char*)&usersSize, sizeof(size_t));
	for (size_t i = 0; i < usersSize; i++)
	{
		writeUserToFile(out, users[i]);
	}

	out.close();
}
