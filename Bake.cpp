#include "Bake.h"
#include <iostream>
using namespace std;

void Bake::continueProcess() {
    cout << "Do you want to continue?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    int choice;
    cin >> choice;
    switch (choice) {
    case 1:
        break;
    case 2:
        cout << "thank you have a nice day";
        exit(0);
        break;
    }
}
