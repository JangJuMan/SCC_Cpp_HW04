#include "BorrowManager.h"

using namespace std;

void BorrowManager::initializeStock(const Book& book, int quantity) 
{
	if (!stock.count(book.title)) 	// ������ ���� �׸��̶��
	{
		stock[book.title] = quantity;
		cout << "[Borrow Manager : �԰�] : " << book.title << " by " << book.author
			<< " " << quantity << " ���� �԰�Ǿ����ϴ�." << endl;
	}
}

bool BorrowManager::borrowBook(const string& title)
{
	if (!stock.count(title))		// �������� �ʴ� å�̶��
	{	
		cout << "[Borrow Manager : �뿩����] : �������� �ʴ� å�Դϴ�." << endl;
		return false;
	}
	if (stock[title] > 0) {			// ��� �����ִٸ�
		--stock[title];
		cout << "[Borrow Manager : �뿩����] : \"" << title << "\" å�� �뿩�߽��ϴ�." << endl;
		return true;
	}
	cout << "[Borrow Manager : �뿩����] : \"" << title << "\" å�� ��� �����մϴ�(��� : " << stock[title] << ")" << endl;
	return false;
}

bool BorrowManager::returnBook(const string& title)
{
	if (!stock.count(title)) {		// �������� �ʴ� å�̶��
		cout << "[Borrow Manager : �ݳ�����] : �������� �ʴ� å�Դϴ�." << endl;
		return false;
	}
	++stock[title];
	cout << "[Borrow Manager : �ݳ�����] : \"" << title << "\" å�� �ݳ��߽��ϴ�.(��� : " << stock[title] << ")" << endl;
	return true;
}

bool BorrowManager::displayStock() {
	if (stock.empty()) {			// ��ϵ� å�� ���� ��,
		cout << "[Borrow Manager : display] : ���� ��ϵ� å�� �����ϴ�." << endl;
		return false;
	}
	cout << "[Borrow Manager : å ���]----------------" << endl;
	for (const auto& book : stock) {
		cout << book.first << " ���(" << book.second << ")" << endl;
	}
	cout << "------------------------------------------\n" << endl;
	return true;
}

int BorrowManager::getStock(const string& title) const {
	auto it = stock.find(title);	// �������� �ʴ� å�� ���� ����ó��
	return (it != stock.end()) ? it->second : -1;
}