#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    string Title;
    int Quantity;

public:
    Book(const string& title, int quantity);
    string getTitle() const;
    int getQuantity() const;
    void decreaseQuantity();
};

#endif // BOOK_H