#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
#include "Library.h"
#include "Products.h"
#include "Bake.h"

using namespace std;

void displayBooks(const string& filename) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File could not be opened!" << endl;
        return;
    }

    cout << "Books:" << endl;
    cout << "****" << endl;

    string line;
    while (getline(file, line)) {
        cout << line << endl;
    }

    file.close();
}

void admin() {
    Library library;
    Products products(library);
    Bake instance;
    bool exit = false;
    while (!exit) {
        cout << "Select the operation you want to perform in the Library Management System" << endl;
        cout << "************" << endl;
        cout << "1. Add Book." << endl;
        cout << "2. Add Student." << endl;
        cout << "3. Show Available Books." << endl;
        cout << "4. History record view" << endl; // Corrected line
        cout << "5. Borrow Book." << endl;
        cout << "6. Rent a Product" << endl;
        cout << "7. Return a Product" << endl;
        cout << "8. Query a Product" << endl;
        cout << "0. Exit." << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
        case 1: {
            string title;
            int quantity;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, title);
            cout << "Enter Quantity: ";
            cin >> quantity;
            library.addBook(title, quantity);
            cout << "Book successfully added." << endl;
            instance.continueProcess();
            break;
        }
        case 2: {
            string id, password;
            cout << "Enter Student ID: ";
            cin >> id;
            cout << "Enter Password: ";
            cin >> password;
            if (!library.studentExists(id, password)) {
                library.addStudent(id, password);
                cout << "Student successfully added." << endl;
            }
            else {
                cout << "This student is already registered!" << endl;
            }
            instance.continueProcess();
            break;
        }
        case 3:
            library.showBooks();
            instance.continueProcess();
            break;
        case 4: {
            ifstream dosya("./student.txt");
            if (dosya.is_open()) {
                string satir;
                while (getline(dosya, satir)) {
                    cout << satir << endl;
                }
                dosya.close();
                instance.continueProcess();
            }
            else {
                cerr << "File not found." << endl;
            }
            break;
        }
        case 5: {
            string studentId, bookTitle;
            cout << "Enter Student ID: ";
            cin >> studentId;
            cout << "Enter Book Title: ";
            cin.ignore();
            getline(cin, bookTitle);
            if (library.borrowBook(studentId, bookTitle)) {
                cout << "Book borrowed." << endl;
            }
            else {
                cout << "Book could not be borrowed." << endl;
            }
            instance.continueProcess();
            break;
        }
        case 6:
            products.rentProduct();
            instance.continueProcess();
            break;
        case 7:
            products.returnProduct();
            instance.continueProcess();
            break;
        case 8:
            products.queryProduct();
            instance.continueProcess();
            break;
        case 0:
            exit = true;
            cout << "Goodbye!" << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    }
}

int main() {
    cout << "Please enter your user type:" << endl;
    cout << "1. User" << endl;
    cout << "2. Administrator" << endl;

    int choice;
    cin >> choice;

    Library library;
    library.addStudent("mdogantatli", "1453");
    library.addAdministrator("admin", "admin11");
    // Example books
    library.addBook("Les Misérables", 10);
    library.addBook("White Ship", 7);
    library.addBook("Crime and Punishment", 15);
    library.addBook("1984", 20);
    library.addBook("The Metamorphosis", 12);

    switch (choice) {
    case 1: {
        string studentId, studentPassword;
        cout << "Enter your username: ";
        cin >> studentId;
        cout << "Enter your password:";
        cin >> studentPassword;

        if (library.studentExists(studentId, studentPassword)) {
            cout << "Login successful!" << endl;
            Products products(library);
            products.process();
        }
        else {
            cout << "Login failed! Please try again." << endl;
        }
        break;
    }
    case 2: {
        string adminId, adminPassword;
        cout << "Enter your username: ";
        cin >> adminId;
        cout << "Enter your password: ";
        cin >> adminPassword;
        if (library.administratorExists(adminId, adminPassword)) {
            cout << "Login successful!" << endl;
            admin();
        }
        else {
            cout << "Login failed! Please try again." << endl;
        }
        break;
    }
    default:
        cout << "Invalid choice." << endl;
        break;
    }

    return 0;
}
