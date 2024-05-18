#include "Library.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>

using namespace std;

bool Library::bookExists(const string& bookTitle) const {
    auto it = find_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getTitle() == bookTitle && book.getQuantity() > 0;
    });
    return it != books.end();
}

void Library::addBook(const string& title, int quantity) {
    books.push_back(Book(title, quantity));
}

void Library::addStudent(const string& id, const string& password) {
    ofstream file("./student.txt", ios::app);
    if (!file.is_open()) {
        cout << "Student file could not be opened." << endl;
        return;
    }

    file << id << " " << password << endl;
    file.close();

    students.push_back(Student(id, password));
}

void Library::showBooks() const {
    ifstream file("./books.txt");
    if (!file.is_open()) {
        cout << "Book files could not be opened." << endl;
        return;
    }

    cout << "Available Books" << endl;
    cout << "*****" << endl;

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}


void Library::addAdministrator(const string& id, const string& password) {
    administrators.push_back(Administrator(id, password));
}

bool Library::studentExists(const string& id, const string& password) const {
    auto it = find_if(students.begin(), students.end(), [&](const Student& student) {
        return student.getId() == id && student.getPassword() == password;
    });
    return it != students.end();
}

bool Library::administratorExists(const string& id, const string& password) const {
    auto it = find_if(administrators.begin(), administrators.end(), [&](const Administrator& administrator) {
        return administrator.getId() == id && administrator.getPassword() == password;
    });
    return it != administrators.end();
}

bool Library::borrowBook(const string& studentId, const string& bookTitle) {
    auto bookIter = find_if(books.begin(), books.end(), [&](const Book& book) {
        return book.getTitle() == bookTitle && book.getQuantity() > 0;
    });

    if (bookIter != books.end()) {
        bookIter->decreaseQuantity();
        cout << "Book available. Borrowing the book...." << endl;
        return true;
    }
    else {
        cout << "Book not available." << endl;
        return false;
    }
}