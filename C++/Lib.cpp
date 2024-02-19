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
        books.push_back(Book("Rich Dad Poor Dad", "Robert Kiyosaki and Sharon Lechter"));
        books.push_back(Book("To Kill a Mockingbird", "Harper Lee"));
        books.push_back(Book("IKIGAI", "Hector Garcia"));
        books.push_back(Book("All I Ever Want is You", "Nikhil Raj"));
    }

    void BooksDatabase() {
        cout << "Books Database:\n";
        for (int i = 0; i < books.size(); i++) {
            if (!books[i].borrowed) {
                cout << i + 1 << ". " << books[i].title << " by " << books[i].author << endl;
            }
        }
    }

    void BooksCheckout(int bookNumber) {
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

    void BooksReturn(int bookNumber) {
        if (bookNumber >= 1 && bookNumber <= books.size()) {
            if (books[bookNumber - 1].borrowed) {
                books[bookNumber - 1].returnBook();
                cout << "You have successfully returned " << books[bookNumber - 1].title << " by " << books[bookNumber - 1].author << endl;
                cout << "Yours Due is zero";
            } else {
                cout << "Sorry, this book is not currently borrowed.\n";
            }
        } else {
            cout << "Invalid book number.\n";
        }
    }
    
    void Finecalculation(int bookNumber) {
    	if (bookNumber >= 1 && bookNumber <= books.size()) {
    		if (books[bookNumber - 1].borrowed) {
    			books[bookNumber - 1].returnBook();
    			cout << "You have successfully paid your fine" << books[bookNumber -1].title << " by " << books[bookNumber - 1].author << end1;
			} else {
				cout << "Sorry, Please Retry later after sometime.\n";
			}
		}
    	
};

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Books Database\n";
        cout << "2. Books Checkout\n";
        cout << "3. Books Return\n";
        cout << "4. Fine Calculation\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                lib.BooksDatabase();
                break;
            case 2:
                int borrowChoice;
                cout << "Enter the book number you want to borrow: ";
                cin >> borrowChoice;
                lib.BooksCheckout(borrowChoice);
                break;
            case 3:
                int returnChoice;
                cout << "Enter the book number you want to return: ";
                cin >> returnChoice;
                lib.BooksReturn(returnChoice);
                break;
            case 4:
                int main() {
                int days;
                cout<<"Enter the number of days:";
                cin>>days;
                if(days>0 && days<=5)
           {
                cout<<"\nPer Day Fine Amount is : 0.50";
                cout<<"\nTotal Fine Amount is : "<<days*0.50;
           }    
                else  if(days>=6 && days<=10)
           {
                cout<<"\nPer Day Fine Amount is : 1";
                cout<<"\nTotal Fine Amount is : "<<days*1;
           }
                else  if(days>10 && days<=30)
           {
                cout<<"\nPer Day Fine Amount is : 5";
                cout<<"\nTotal Fine Amount is : "<<days*5;
           }
                else {
                cout<<"\nYou will Blacklisted.";
           }
           
       return 0;
}
            case 5:
                exit(0);
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    return 0;
}
