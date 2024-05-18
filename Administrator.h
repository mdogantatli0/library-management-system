#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <string>
using namespace std;

class Administrator {
private:
    string ID;
    string Password;

public:
    Administrator(const string& id, const string& password);
    string getId() const;
    string getPassword() const;
};

#endif // ADMINISTRATOR_H