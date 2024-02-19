#include<iostream>
#<vector>
#include<algorithm>
#include <ctime>
using namespace std;

class Book {
public:
    string title;
    bool isAvailable;
    time_t dueDate;

    Book(string t, bool a) {
        title = t;
        isAvailable = a;
        dueDate = time(0);
    }

    int calculateFine() {
        time_t currentTime = time(0);
        int fine = 0;
        if (isAvailable && difftime(currentTime, dueDate) > 0) {
            fine = (difftime(currentTime, dueDate) / (24 * 60 * 60)) * 10; // 10 cents per day
        }
        return fine;
    }
};

class Library {
private:
    vector<Book> books;

public:
     Library() {
        books.push_back(Book("Rich Dad Poor Dad", "Robert Kiyosaki and Sharon Lechter"));
        books.push_back(Book("To Kill a Mockingbird", "Harper Lee"));
        books.push_back(Book("IKIGAI", "Hector Garcia"));
        books.push_back(Book("All I Ever Want is You", "Nikhil Raj"));
    }

    void borrowBook() {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title && books[i].isAvailable) {
                books[i].isAvailable = false;
                cout << "Enter due date (YYYY-MM-DD): ";
                string input;
                cin >> input;
                books[i].dueDate = time_t(mktime(std::put_time(std::localtime(std::time(0)), input.c_str())));
                cout << "Book borrowed successfully." << endl;
                return;
            }
        }
        cout << "Book not available." << endl;
    }

    void returnBook() {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title && !books[i].isAvailable) {
                books[i].isAvailable = true;
                int fine = books[i].calculateFine();
                if (fine > 0) {
                    cout << "Fine: $" << fine / 100 << "." << fine % 100 << endl;
                }
                cout << "Book returned successfully." << endl;
                return;
            }
        }
        cout << "Invalid book or already available." << endl;
    }

    void bookAvailability() {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].title == title) {
                if (books[i].isAvailable)
                    cout << "The book is available." << endl;
                else
                    cout << "The book is currently borrowed. Due date: " << ctime(&books[i].dueDate);
                return;
            }
        }
        cout << "Invalid book title." << endl;
    }

    void listAllBooks() {
        cout << "List of all books: " << endl;
        for (int i = 0; i < books.size(); i++) {
            cout << books[i].title << (books[i].isAvailable ? " - Available" : " - Borrowed") << endl;
        }
    }
};

int main() {
    Library lib;

    lib.addBook("Book 1");
    lib.addBook("Book 2");
    lib.addBook("Book 3");

    lib.borrowBook("Book 1");
    lib.borrowBook("Book 2");

    lib.listAllBooks();

    lib.returnBook("Book 1");

    lib.bookAvailability("Book 2");

    return 0;
}
