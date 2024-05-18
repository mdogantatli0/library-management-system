#include "Book.h"

Book::Book(const string& title, int quantity) : Title(title), Quantity(quantity) {}

string Book::getTitle() const {
    return Title;
}

int Book::getQuantity() const {
    return Quantity;
}

void Book::decreaseQuantity() {
    Quantity--;
}