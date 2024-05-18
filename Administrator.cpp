#include "Administrator.h"

Administrator::Administrator(const string& id, const string& password) : ID(id), Password(password) {}

string Administrator::getId() const {
    return ID;
}

string Administrator::getPassword() const {
    return Password;
}