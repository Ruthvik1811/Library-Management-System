
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
public:
    string title;
    string author;
    int id;
    bool checkedOut;

    Book(string title, string author, int id) {
        this->title = title;
        this->author = author;
        this->id = id;
        this->checkedOut = false;
    }
};

class Library {
public:
    vector<Book> books;

    void addBook(Book book) {
        books.push_back(book);
    }

    void removeBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                books.erase(books.begin() + i);
                break;
            }
        }
    }

    void checkoutBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                if (books[i].checkedOut) {
                    cout << "Book is already checked out." << endl;
                } else {
                    books[i].checkedOut = true;
                    cout << "Book checked out successfully." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }

    void returnBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].id == id) {
                if (books[i].checkedOut) {
                    books[i].checkedOut = false;
                    cout << "Book returned successfully." << endl;
                } else {
                    cout << "Book was not checked out." << endl;
                }
                return;
            }
        }
        cout << "Book not found." << endl;
    }
};

int main() {
    Library library;

    // Add books to library
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1));
    library.addBook(Book("1984", "George Orwell", 2));
    library.addBook(Book("Brave New World", "Aldous Huxley", 3));

    // Checkout a book
    library.checkoutBook(1);

    // Try to checkout a book that is already checked out
    library.checkoutBook(1);

    // Return a book
    library.returnBook(1);

    // Remove a book
    library.removeBook(3);

    return 0;
}

