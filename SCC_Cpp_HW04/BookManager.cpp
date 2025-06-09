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
	cout << "[Book Manager : �����߰�] " << title << " by " << author << endl;
}

void BookManager::displayAllBooks() const 
{
	if (books.empty()) 
	{
		cout << "[Book Manager : display] ���� ��ϵ� å�� �����ϴ�." << endl;
		return;
	}

	cout << "[Book Manager : ���� ���� ���]-----------" << endl;
	for (size_t i = 0; i < books.size(); ++i) 
	{
		cout << "- " << books[i].title << " by " << books[i].author << endl;
	}
	cout << "------------------------------------------\n" << endl;
}

Book* BookManager::searchBookByTitle(const string& title)
{
	Book* toFind = findBookByTitle(title);
	cout << "[Book Manager : ���� �˻����] : ";
	if (toFind) 
	{
		cout << toFind->title << " by " << toFind->author;
		return toFind;
	}
	cout << "�ش� ������ å�� ã�� �� �����ϴ�." << endl;
	return nullptr;
}

Book* BookManager::searchBookByAuthor(const string& author)
{
	Book* toFind = findBookByAuthor(author);
	cout << "[Book Manager : ���� �˻����] : ";
	if (toFind) 
	{
		cout << toFind->title << " by " << toFind->author;
		return toFind;
	}
	cout << "�ش� �۰��� å�� ã�� �� �����ϴ�." << endl;
	return nullptr;
}