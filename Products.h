#ifndef PRODUCTS_H
#define PRODUCTS_H

#include "Library.h"

class Products {
private:
    Library& library;

public:
    Products(Library& lib);
    void process();
    void rentProduct();
    void returnProduct();
    void queryProduct();
    void bookQuery();
};

#endif // PRODUCTS_H
