#include <iostream>
#include <string>
#include <vector>
#include <ctime>

class Book {
public:
    Book(std::string title, std::string, int publishedYear)
        : title_(title), author_(author), publishedYear_(publishedYear) {}

    std::string title_;
    std::string author_;
    int publishedYear_;
    time_t due_date_;
};

class Member {
public:
    Member(std::string name, time_t membershipDate, std::string creditCardNumber, std::string creditCardExpirationDate, std::string creditCardCVV)
        : name_(name), membershipDate_(membershipDate), creditCard_(creditCardNumber, creditCardExpirationDate, creditCardCVV) {}

    void borrowBook(Book& book) {
        borrowedBooks_.push_back(book);
        time_t currentTime = time(0);
        due_date_ = currentTime + 14 * 24 * 60 * 60; // 14 days in seconds
        borrowedBooks_.back().due_date_ = due_date_;
    }

    void returnBook(Book& book) {
        borrowedBooks_.erase(std::remove(borrowedBooks_.begin(), borrowedBooks_.end(), book), borrowedBooks_.end());
        book.due_date_ = 0;
    }

    int calculateFine() {
        time_t currentTime = time(0);
        int fine = 0;
        for (auto& book : borrowedBooks_) {
            if (book.due_date_ > 0 && book.due_date_ < currentTime) {
                int daysOverdue = (currentTime - book.due_date_) / (24 * 60 * 60);
                fine += daysOverdue;
            }
        }
        return fine;
    }

    void chargeFine(int fine) {
        creditCard_.charge(fine);
    }

private:
    std::string name_;
    time_t membershipDate_;
    std::vector<Book> borrowedBooks_;
    CreditCard creditCard_;
};

class CreditCard {
public:
    CreditCard(std::string number, std::string expirationDate, std::string cvv)
        : number_(number), expirationDate_(expirationDate), cvv_(cvv) {}

    void charge(int amount) {
        // Implement credit card charging logic here
    }

private:
    std::string number_;
    std::string expirationDate_;
    std::string cvv_;
};

int main() {
    // Create library
    Library library;

    // Add books to library
    Book book1("Harry Potter", "J.K. Rowling", 1997);
    Book book2("Outliers", "Malcolm Gladwell", 2008);
    library.addBook(book1);
    library.addBook(book2);

    // Add members to library
    time_t membershipDate = time(0);
    CreditCard creditCard("1234-5678-9012-3456", "12/24", "123");
    Member member1("Alice", membershipDate, creditCard);
    Member member2("Bob", membershipDate, creditCard);
    library.addMember(member1);
    library.addMember(member2);

    // Members borrow books
    member1.borrowBook(book1);
    member2.borrowBook(book2);

    // Check fines after one month
    time_t currentTime = time(0);
    book1.due_date_ = currentTime - 24 * 60 * 60; // One day overdue
    book2.due_date_ = currentTime - 24 * 60 * 60; // One day overdue

    int fine = member1.calculateFine();
    member1.chargeFine(fine);

    std::cout << "Alice's fine: " << fine << std::endl;

    return 0;
}
