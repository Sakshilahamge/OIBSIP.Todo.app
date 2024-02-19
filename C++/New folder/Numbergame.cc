#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    bool borrowed;

    Book(string t, string a) : title(t), author(a), borrowed(false) {}

    void borrowBook() {
        borrowed = true;
    }

    void returnBook() {
        borrowed = false;
    }
};

class Library {
private:
    vector<Book> books;

public:
    Library() {
        books.push_back(Book("The Great Gatsby", "F. Scott Fitzgerald"));
        books.push_back(Book("To Kill a Mockingbird", "Harper Lee"));
        books.push_back(Book("Pride and Prejudice", "Jane Austen"));
    }

    void displayAvailableBooks() {
        cout << "Available books in the library are:\n";
        for (int i = 0; i < books.size(); i++) {
            if (!books[i].borrowed) {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
            }
        }
    }

    void borrowBook(int bookNumber) {
        if (bookNumber >= 1 && bookNumber <= books.size()) {
            if (!books[bookNumber - 1].borrowed) {
                books[bookNumber - 1].borrowBook();
                cout << "You have successfully borrowed " << books[bookNumber - 1].title << " by " << books[bookNumber - 1].author << endl;
            } else {
                cout << "Sorry, this book is currently borrowed.\n";
            }
        } else {
            cout << "Invalid book number.\n";
        }
    }

    void returnBook(int bookNumber) {
        if (bookNumber >= 1 && bookNumber <= books.size()) {
            if (books[bookNumber - 1].borrowed) {
                books[bookNumber - 1].returnBook();
                cout << "You have successfully returned " << books[bookNumber - 1].title << " by " << books[bookNumber - 1].author << endl;
            } else {
                cout << "Sorry, this book is not currently borrowed.\n";
            }
        } else {
            cout << "Invalid book number.\n";
        }
    }
};

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Display available books\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.displayAvailableBooks();
                break;
            case 2:
                int borrowChoice;
                cout << "Enter the book number you want to borrow: ";
                cin >> borrowChoice;
                lib.borrowBook(borrowChoice);
                break;
            case 3:
                int returnChoice;
                cout << "Enter the book number you want to return: ";
                cin >> returnChoice;
                lib.returnBook(returnChoice);
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}