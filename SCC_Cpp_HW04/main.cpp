#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main() {
    BookManager bookManager;
    BorrowManager borrowManager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;         // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl;    // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 제목으로 책 검색" << endl; // 검색
        cout << "4. 작가로 책 검색" << endl;  // 검색
        cout << "5. 책 대여하기" << endl;    // 대여하기
        cout << "6. 책 반납하기" << endl;    // 반납하기
        cout << "7. 종료" << endl;          // 프로그램 종료
        cout << "선택: ";

        int choice;         // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (cin.fail()){     // 잘못된 입력 예외처리
            cin.clear();    // 입력 실패 상태 초기화
            cin.ignore(numeric_limits<streamsize>::max(), '\n');    // 입력 버퍼 초기화
            cout << "[ERR] 잘못된 입력입니다. 숫자를 입력하세요" << endl;
            continue;
        }

        cin.ignore();           // 개행문자 제거

        if (choice == 1) {      // 책 추가하기(제목, 저자명)
            string title, author;
            cout << "책 제목: ";
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)

            bookManager.addBook(title, author); // 입력받은 책 정보를 추가
            borrowManager.initializeStock(Book(title, author));  // 재고 초기화(3권)
        }
        else if (choice == 2) { // BookManager가 보유중인 책 모두 출력
            bookManager.displayAllBooks();
        }
        else if (choice == 3) { // 책 제목으로 검색
            string title;
            cout << "책 제목: ";
            getline(cin, title);
            Book* target = bookManager.searchBookByTitle(title);
            if (target){  // 검색 결과가 있다면
                cout << " 재고(" << borrowManager.getStock(target->title) << ")" << endl;
            }
        }
        else if (choice == 4) { // 책 저자로 검색
            string author;
            cout << "책 저자 : ";
            getline(cin, author);
            Book* target = bookManager.searchBookByAuthor(author);
            if (target){         // 검색 결과가 있다면
                cout << " 재고(" << borrowManager.getStock(target->title) << ")" << endl;
            }
        }
        else if (choice == 5) { // 책 대여하기
            if (!borrowManager.displayStock()) {    // 책 목록이 있다면 표시
                continue;                           // 없다면 메인메뉴로 돌아가기
            }
            string title;
            cout << "어느 책을 대여하시겠습니까?" << endl;
            cout << "책 제목 : ";
            getline(cin, title);
            borrowManager.borrowBook(title);
        }
        else if (choice == 6) { // 책 반납하기
            if (!borrowManager.displayStock()) {    // 책 목록이 있다면 표시
                continue;                           // 없다면 메인메뉴로 돌아가기
            }
            string title;
            cout << "어느 책을 반납하시겠습니까?" << endl;
            cout << "책 제목 : ";
            getline(cin, title);
            borrowManager.returnBook(title);    
        }
        else if (choice == 7) { // 프로그램 종료
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        }
        else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
