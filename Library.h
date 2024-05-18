#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"
#include "Student.h"
#include "Administrator.h"

using namespace std;

class Library {
private:
    vector<Book> books;
    vector<Student> students;
    vector<Administrator> administrators;

public:
    bool bookExists(const string& bookTitle) const;
    void addBook(const string& title, int quantity);
    void addStudent(const string& id, const string& password);
    void addAdministrator(const string& id, const string& password);
    bool studentExists(const string& id, const string& password) const;
    bool administratorExists(const string& id, const string& password) const;
    void showBooks() const;
    bool borrowBook(const string& studentId, const string& bookTitle);
};

#endif // LIBRARY_H