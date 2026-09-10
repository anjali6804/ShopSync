#include "../include/order.h"
#include <iostream>
#include <iomanip>

Order::Order(int id)
    : orderId(id), totalAmount(0)
{
}

void Order::addProduct(const CartItem& item)
{
    items.push_back(item);
}

void Order::calculateTotal()
{
    totalAmount = 0;

    for (const CartItem& item : items)
    {
        totalAmount += item.product.getPrice() * item.quantity;
    }
}

void Order::displayOrder() const
{
    std::cout << "\n========== ORDER ==========\n";
    std::cout << "Order ID : " << orderId << '\n';

    for (const CartItem& item : items)
    {
        item.product.productDetails();

        std::cout << "Quantity   : " << item.quantity << '\n';

        std::cout << "Subtotal   : "
                  << std::fixed << std::setprecision(2)
                  << item.product.getPrice() * item.quantity
                  << '\n';

        std::cout << "-------------------------\n";
    }

    std::cout << "Total Amount : "
              << std::fixed << std::setprecision(2)
              << totalAmount << '\n';
}

int Order::getOrderId() const
{
    return orderId;
}

double Order::getTotalAmount() const
{
    return totalAmount;
}