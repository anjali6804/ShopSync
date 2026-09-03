#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H
using namespace std;
#include "product.h"
#include <vector>

class ProductManager {
private:
    vector<Product> products;

public:
    void addProduct(const Product& product);

    bool removeProduct(int id);

    Product* findProduct(int id);

    void displayAllProducts() const;
};

#endif