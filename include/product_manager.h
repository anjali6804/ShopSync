#ifndef PRODUCT_MANAGER_H
#define PRODUCT_MANAGER_H
using namespace std;
#include "product.h"
#include <unordered_map>
#include <string>

class ProductManager {
private:
    std::unordered_map<int, Product> products;
public:
    void addProduct(const Product& product);
    
    bool removeProduct(int id);

    Product* findProduct(int id);
    Product* findProductByName(const std::string& name);

    void displayAllProducts() const;

    void updateProductPrice(int id, double newPrice);
    void updateProductStock(int id, int newStock);

    void sortByPrice();
    void sortByStock();

    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif