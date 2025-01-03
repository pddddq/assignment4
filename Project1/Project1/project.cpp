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
	}//å �߰�

	Book* findBookByTitle(string title) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].title == title)
				return &books[i];
		}
		return nullptr;
	}//title�� å �˻�, ������ ������ ��ȯ, ���н� nullptr��ȯ

	Book* findBookByAuthor(string author) {
		for (int i = 0; i < books.size(); i++) {
			if (books[i].author == author)
				return &books[i];
		}
		return nullptr;
	}//author�� å �˻�

	void displayAllBooks() {
		if (books.empty()) {
			cout << "å�� ����־��\n";
			return;
		}
		for (size_t i = 0; i < books.size(); i++) {
			cout << "���� : " << books[i].title << ", ���� : " << books[i].author << endl;
		}
	}//��� å ���
};

class BorrowManager {
private:
	unordered_map<string, int> stock;

	void initializeStock(Book book, int quantity = 3) {
		stock[book.title] = quantity;
	}//å �ʱ���� 3���� ����
};

int main() {
	BookManager bookManager;

	bookManager.addBook("c++ ���α׷���", "������");
	bookManager.addBook("�𸮾�", "������");

	cout << "���å ���" << endl;
	bookManager.displayAllBooks();

	string titleToSearch = "c++ ���α׷���";
	Book* foundBook1 = bookManager.findBookByTitle(titleToSearch);

	if (foundBook1) {
		cout << "�˻�" << endl;
		cout << "���� : " << foundBook1->title << ", ����: " << foundBook1->author << endl;
	}
	else {
		cout << "�˻�" << endl;
		cout << "\"" << titleToSearch << "\"(��)��� ������ å�� ã�� �� �����ϴ�." << endl;
	}

	string titleSearch = "c++ ���η���";
	Book* foundBook2 = bookManager.findBookByTitle(titleSearch);

	if (foundBook2) {
		cout << "�˻�" << endl;
		cout << "���� : " << foundBook2->title << ", ����: " << foundBook2->author << endl;
	}
	else {
		cout << "�˻�" << endl;
		cout << "\"" << titleSearch << "\"(��)��� ������ å�� ã�� �� �����ϴ�." << endl;
	}
}