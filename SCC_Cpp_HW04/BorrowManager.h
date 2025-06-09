#pragma once
#include "Book.h"
#include <unordered_map>
#include <string> 
#include <iostream>

class BorrowManager {
private:
	std::unordered_map<std::string, int> stock;

public:
	void initializeStock(const Book& book, int quantity = 3);
	bool borrowBook(const std::string& title);
	bool returnBook(const std::string& title);
	bool displayStock();
	int getStock(const std::string& title) const;
};