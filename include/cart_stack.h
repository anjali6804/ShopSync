#ifndef CART_STACK_H
#define CART_STACK_H

#include "cart.h"
#include <stack>

class CartStack
{
private:
    std::stack<CartItem> history;

public:
    void push(const CartItem& item);
    CartItem pop();
    bool isEmpty() const;
};

#endif