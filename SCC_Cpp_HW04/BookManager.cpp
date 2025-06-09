#include "BookManager.h"
#include <iostream>

using namespace std;

Book* BookManager::findBookByTitle(const string& title) 
{
	for (auto& book : books) 
	{
		if (book.title == title) 
		{
			return &book;
		}
	}
	return nullptr;
}

Book* BookManager::findBookByAuthor(const string& author) 
{
	for (auto& book : books) 
	{
		if (book.author == author) 
		{
			return &book;
		}
	}
	return nullptr;
}

void BookManager::addBook(const string& title, const string& author) 
{
	books.push_back(Book(title, author));
	cout << "[Book Manager : 도서추가] " << title << " by " << author << endl;
}

void BookManager::displayAllBooks() const 
{
	if (books.empty()) 
	{
		cout << "[Book Manager : display] 현재 등록된 책이 없습니다." << endl;
		return;
	}

	cout << "[Book Manager : 현재 도서 목록]-----------" << endl;
	for (size_t i = 0; i < books.size(); ++i) 
	{
		cout << "- " << books[i].title << " by " << books[i].author << endl;
	}
	cout << "------------------------------------------\n" << endl;
}

Book* BookManager::searchBookByTitle(const string& title)
{
	Book* toFind = findBookByTitle(title);
	cout << "[Book Manager : 제목 검색결과] : ";
	if (toFind) 
	{
		cout << toFind->title << " by " << toFind->author;
		return toFind;
	}
	cout << "해당 제목의 책을 찾을 수 없습니다." << endl;
	return nullptr;
}

Book* BookManager::searchBookByAuthor(const string& author)
{
	Book* toFind = findBookByAuthor(author);
	cout << "[Book Manager : 제목 검색결과] : ";
	if (toFind) 
	{
		cout << toFind->title << " by " << toFind->author;
		return toFind;
	}
	cout << "해당 작가의 책을 찾을 수 없습니다." << endl;
	return nullptr;
}