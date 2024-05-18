#include "Student.h"

Student::Student(const string& id, const string& password) : ID(id), Password(password) {}

string Student::getId() const {
    return ID;
}

string Student::getPassword() const {
    return Password;
}