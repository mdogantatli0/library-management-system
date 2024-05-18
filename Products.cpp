#include "Products.h"
#include <iostream>

using namespace std;

Products::Products(Library& lib) : library(lib) {}

void Products::process() {
    cout << "Select the action you want to perform:" << endl;
    cout << "1. Rent a Product" << endl;
    cout << "2. Return a Product" << endl;
    cout << "3. Query a Product" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        rentProduct();
        break;
    case 2:
        returnProduct();
        break;
    case 3:
        queryProduct();
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
        break;
    }
}

void Products::rentProduct() {
    cout << "Product rental option selected." << endl;
    bookQuery();
}

void Products::returnProduct() {
    cout << "Product return option selected." << endl;
    bookQuery();
}

void Products::queryProduct() {
    cout << "Product query option selected." << endl;
    bookQuery();
}

void Products::bookQuery() {
    string bookTitle;
    cout << "Enter the book title: ";
    cin.ignore();
    getline(cin, bookTitle);
    if (library.bookExists(bookTitle)) {
        cout << "Product is available. You can take the product for 15 days, if it exceeds the time, the daily fee is: 1TL." << endl;
        cout << "Product is being taken" << endl;
        cout << "successfully received good days;" << endl;
    }
    else {
        cout << "Product not available." << endl;
    }
}
