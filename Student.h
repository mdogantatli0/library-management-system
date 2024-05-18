#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string ID;
    string Password;

public:
    Student(const string& id, const string& password);
    string getId() const;
    string getPassword() const;
};

#endif