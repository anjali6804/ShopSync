#include "../include/cart.h"
#include <iostream>
#include <iomanip>

void Cart::addItem(const Product& product, int quantity)
{
    if (quantity <= 0)
    {
        std::cout << "Invalid quantity!\n";
        return;
    }

    if (quantity > product.getStock())
    {
        std::cout << "Insufficient stock!\n";
        return;
    }

    for (CartItem& item : items)
    {
        if (item.product.getId() == product.getId())
        {
            if (item.quantity + quantity > product.getStock())
            {
                std::cout << "Insufficient stock!\n";
                return;
            }

            item.quantity += quantity;
            return;
        }
    }

    CartItem newItem = {product, quantity};
    items.push_back(newItem);
}
bool Cart::removeItem(int id)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->product.getId() == id)
        {
            items.erase(it);
            return true;
        }
    }

    return false;
}

void Cart::displayCart() const
{
    if (items.empty())
    {
        std::cout << "Cart is empty!\n";
        return;
    }

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
}

double Cart::calculateTotal() const
{
    double total = 0;

    for (const CartItem& item : items)
    {
        total += item.product.getPrice() * item.quantity;
    }

    return total;
}
const std::vector<CartItem>& Cart::getItems() const
{
    return items;
}
void Cart::clear()
{
    items.clear();
}