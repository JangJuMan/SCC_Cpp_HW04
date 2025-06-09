#pragma once
#include <string>

class Book {
public:
	std::string title;
	std::string author;

	Book(const std::string& title, const std::string& author);
};