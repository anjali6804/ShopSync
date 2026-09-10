#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
using namespace std;
class Product {
private:
    int id;
    string name;
    double price;
    int stock;
    string category;

public:
    Product(int id, const string& name, double price,int stock, const string& category);
    
    void addStock(int quantity);
    bool subtractStock(int quantity);
    double discountPrice(double percentage) const;
    void productDetails() const;

    int getId() const;

    void updatePrice(double newPrice);
    void updateStock(int newStock);
    double getPrice() const;
    int getStock() const;
    std::string getName() const;
    std::string getCategory() const;
};
#endif 
