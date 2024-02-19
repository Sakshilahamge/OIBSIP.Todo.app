#include<iostream>
#include<ctime>

using namespace std;

class Book {
    public:
    string title;
    int book_id;
    int days_late;
    Book(string t, int i, int d) {
        title = t;
        book_id = i;
        days_late = d;
    }
};

int main() {
    int choice, book_id, days_late;
    string title;
    Book book;

    do {
        cout << "1. Add a new book" << endl;
        cout << "2. Calculate Fine" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "Enter book title: ";
                cin >> title;
                cout << "Enter book id: ";
                cin >> book_id;
                book = Book(title, book_id, 0);
                cout << "Book added successfully" << endl;
                break;

            case 2:
                cout << "Enter book id: ";
                cin >> book_id;
                if(book.book_id == book_id) {
                    cout << "Enter days late: ";
                    cin >> days_late;
                    time_t current_time = time(0);
                    tm *ltm = localtime(&current_time);
                    int current_date = ltm->tm_mday;
                    cout << "Total fine: " << (days_late * 1) + (current_date - days_late) << endl;
                } else {
                    cout << "Book not found" << endl;
                }
                break;

            case 3:
                cout << "Exiting the program..." << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
        }
    } while(choice != 3);

    return 0;
}
