#ifndef ORDER_H
#define ORDER_H

#include "product.h"
#include <vector>
#include "cart.h"

class Order
{
private:
    int orderId;
    std::vector<CartItem> items;
    double totalAmount;

public:
    Order(int id);

    void addProduct(const CartItem& item);

    void calculateTotal();

    void displayOrder() const;

    int getOrderId() const;
    double getTotalAmount() const;
};

#endif