#pragma once
#include "Book.h"
#include <vector>

class BookManager {
private:
	std::vector<Book> books;

protected:
	Book* findBookByTitle(const std::string& title);
	Book* findBookByAuthor(const std::string& author);

public:
	void addBook(const std::string& title, const std::string& author);
	void displayAllBooks() const;
	Book* searchBookByTitle(const std::string& title);
	Book* searchBookByAuthor(const std::string& author);
};