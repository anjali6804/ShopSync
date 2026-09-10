#ifndef CART_H
#define CART_H

#include "product.h"
#include <vector>

struct CartItem
{
    Product product;
    int quantity;
};

class Cart
{
private:
    std::vector<CartItem> items;

public:
    void addItem(const Product& product, int quantity);
    bool removeItem(int id);
    void displayCart() const;
    double calculateTotal() const;
    const std::vector<CartItem>& getItems() const;
    void clear();
};

#endif