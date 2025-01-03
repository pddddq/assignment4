#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Book {
public:
	string title;
	string author;

	Book(string title, string author)
		: title(title), author(author) {}
};

class BookManager {
private:
	vector<Book> books;

public:
	void addBook(string title, string author) {
		books.emplace_back(title, author);
	}//책 추가

	Book* findBookByTitle(string title) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].title == title)
				return &books[i];
		}
		return nullptr;
	}//title로 책 검색, 성공시 포인터 반환, 실패시 nullptr반환

	Book* findBookByAuthor(string author) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].author == author)
				return &books[i];
		}
		return nullptr;
	}//author로 책 검색

	void displayAllBooks() {
		if (books.empty()) {
			cout << "책이 비어있어용\n";
			return;
		}
		for (size_t i = 0; i < books.size(); i++) {
			cout << "제목 : " << books[i].title << ", 저자 : " << books[i].author << endl;
		}
	}//모든 책 출력
};

class BorrowManager {
private:
	unordered_map<string, int> stock;

	void initializeStock(Book book, int quantity = 3) {
		stock[book.title] = quantity;
	}//책 초기재고 3으로 설정
};

int main() {
	BookManager bookManager;

	bookManager.addBook("c++ 프로그래밍", "어익후");
	bookManager.addBook("언리얼", "아익후");

	cout << "모든책 출력" << endl;
	bookManager.displayAllBooks();

	string titleToSearch = "c++ 프로그래밍";
	Book* foundBook1 = bookManager.findBookByTitle(titleToSearch);

	if (foundBook1) {
		cout << "검색" << endl;
		cout << "제목 : " << foundBook1->title << ", 저자: " << foundBook1->author << endl;
	}
	else {
		cout << "검색" << endl;
		cout << "\"" << titleToSearch << "\"(이)라는 제목의 책을 찾을 수 없습니다." << endl;
	}

	string titleSearch = "c++ 프로래밍";
	Book* foundBook2 = bookManager.findBookByTitle(titleSearch);

	if (foundBook2) {
		cout << "검색" << endl;
		cout << "제목 : " << foundBook2->title << ", 저자: " << foundBook2->author << endl;
	}
	else {
		cout << "검색" << endl;
		cout << "\"" << titleSearch << "\"(이)라는 제목의 책을 찾을 수 없습니다." << endl;
	}
}