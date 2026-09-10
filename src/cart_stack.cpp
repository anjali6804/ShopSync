#include "../include/cart_stack.h"

void CartStack::push(const CartItem& item)
{
    history.push(item);
}

CartItem CartStack::pop()
{
    CartItem item = history.top();
    history.pop();

    return item;
}

bool CartStack::isEmpty() const
{
    return history.empty();
}