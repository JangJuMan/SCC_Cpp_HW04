#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main() {
    BookManager bookManager;
    BorrowManager borrowManager;

    // ������ ���� ���α׷��� �⺻ �޴��� �ݺ������� ����Ͽ� ����� �Է��� ó���մϴ�.
    // ���α׷� ���Ḧ �����ϱ� ������ ��� �����մϴ�.
    while (true) {
        cout << "\n������ ���� ���α׷�" << endl;
        cout << "1. å �߰�" << endl;         // å ������ �Է¹޾� å ��Ͽ� �߰�
        cout << "2. ��� å ���" << endl;    // ���� å ��Ͽ� �ִ� ��� å ���
        cout << "3. �������� å �˻�" << endl; // �˻�
        cout << "4. �۰��� å �˻�" << endl;  // �˻�
        cout << "5. å �뿩�ϱ�" << endl;    // �뿩�ϱ�
        cout << "6. å �ݳ��ϱ�" << endl;    // �ݳ��ϱ�
        cout << "7. ����" << endl;          // ���α׷� ����
        cout << "����: ";

        int choice;         // ������� �޴� ������ ����
        cin >> choice;

        if (cin.fail()){     // �߸��� �Է� ����ó��
            cin.clear();    // �Է� ���� ���� �ʱ�ȭ
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // �Է� ���� �ʱ�ȭ
            cout << "[ERR] �߸��� �Է��Դϴ�. ���ڸ� �Է��ϼ���" << endl;
            continue;
        }

        cin.ignore();           // ���๮�� ����

        if (choice == 1) {      // å �߰��ϱ�(����, ���ڸ�)
            string title, author;
            cout << "å ����: ";
            getline(cin, title); // ���� �Է� (���� ����)
            cout << "å ����: ";
            getline(cin, author); // ���ڸ� �Է� (���� ����)

            bookManager.addBook(title, author); // �Է¹��� å ������ �߰�
            borrowManager.initializeStock(Book(title, author));  // ��� �ʱ�ȭ(3��)
        }
        else if (choice == 2) { // BookManager�� �������� å ��� ���
            bookManager.displayAllBooks();
        }
        else if (choice == 3) { // å �������� �˻�
            string title;
            cout << "å ����: ";
            getline(cin, title);
            Book* target = bookManager.searchBookByTitle(title);
            if (target){  // �˻� ����� �ִٸ�
                cout << " ���(" << borrowManager.getStock(target->title) << ")" << endl;
            }
        }
        else if (choice == 4) { // å ���ڷ� �˻�
            string author;
            cout << "å ���� : ";
            getline(cin, author);
            Book* target = bookManager.searchBookByAuthor(author);
            if (target){         // �˻� ����� �ִٸ�
                cout << " ���(" << borrowManager.getStock(target->title) << ")" << endl;
            }
        }
        else if (choice == 5) { // å �뿩�ϱ�
            if (!borrowManager.displayStock()) {    // å ����� �ִٸ� ǥ��
                continue;                           // ���ٸ� ���θ޴��� ���ư���
            }
            string title;
            cout << "��� å�� �뿩�Ͻðڽ��ϱ�?" << endl;
            cout << "å ���� : ";
            getline(cin, title);
            borrowManager.borrowBook(title);
        }
        else if (choice == 6) { // å �ݳ��ϱ�
            if (!borrowManager.displayStock()) {    // å ����� �ִٸ� ǥ��
                continue;                           // ���ٸ� ���θ޴��� ���ư���
            }
            string title;
            cout << "��� å�� �ݳ��Ͻðڽ��ϱ�?" << endl;
            cout << "å ���� : ";
            getline(cin, title);
            borrowManager.returnBook(title);    
        }
        else if (choice == 7) { // ���α׷� ����
            cout << "���α׷��� �����մϴ�." << endl;
            break; // while ���� ����
        }
        else {
            // �߸��� �Է� ó��
            // �޴��� ���� ��ȣ�� �Է����� ��� ��� �޽����� ����մϴ�.
            cout << "�߸��� �Է��Դϴ�. �ٽ� �õ��ϼ���." << endl;
        }
    }

    return 0; // ���α׷� ���� ����
}
