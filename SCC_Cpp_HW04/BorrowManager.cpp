#include "BorrowManager.h"

using namespace std;

void BorrowManager::initializeStock(const Book& book, int quantity) 
{
	if (!stock.count(book.title)) 	// 기존에 없는 항목이라면
	{
		stock[book.title] = quantity;
		cout << "[Borrow Manager : 입고] : " << book.title << " by " << book.author
			<< " " << quantity << " 권이 입고되었습니다." << endl;
	}
}

bool BorrowManager::borrowBook(const string& title)
{
	if (!stock.count(title))		// 존재하지 않는 책이라면
	{	
		cout << "[Borrow Manager : 대여실패] : 존재하지 않는 책입니다." << endl;
		return false;
	}
	if (stock[title] > 0) {			// 재고가 남아있다면
		--stock[title];
		cout << "[Borrow Manager : 대여성공] : \"" << title << "\" 책을 대여했습니다." << endl;
		return true;
	}
	cout << "[Borrow Manager : 대여실패] : \"" << title << "\" 책의 재고가 부족합니다(재고 : " << stock[title] << ")" << endl;
	return false;
}

bool BorrowManager::returnBook(const string& title)
{
	if (!stock.count(title)) {		// 존재하지 않는 책이라면
		cout << "[Borrow Manager : 반납실패] : 존재하지 않는 책입니다." << endl;
		return false;
	}
	++stock[title];
	cout << "[Borrow Manager : 반납성공] : \"" << title << "\" 책을 반납했습니다.(재고 : " << stock[title] << ")" << endl;
	return true;
}

bool BorrowManager::displayStock() {
	if (stock.empty()) {			// 등록된 책이 없을 때,
		cout << "[Borrow Manager : display] : 현재 등록된 책이 없습니다." << endl;
		return false;
	}
	cout << "[Borrow Manager : 책 목록]----------------" << endl;
	for (const auto& book : stock) {
		cout << book.first << " 재고(" << book.second << ")" << endl;
	}
	cout << "------------------------------------------\n" << endl;
	return true;
}

int BorrowManager::getStock(const string& title) const {
	auto it = stock.find(title);	// 존재하지 않는 책에 대한 예외처리
	return (it != stock.end()) ? it->second : -1;
}