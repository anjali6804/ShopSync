#include "../include/cart_stack.h"
#include <iostream>

int main()
{
    Product laptop(101, "Laptop", 55000, 10, "Electronics");
    Product mouse(102, "Mouse", 800, 20, "Accessories");

    CartItem item1 = {laptop, 1};
    CartItem item2 = {mouse, 2};

    CartStack stack;

    stack.push(item1);
    stack.push(item2);

    std::cout << "Popping from stack:\n";

    CartItem item = stack.pop();

    std::cout << "Product ID: "
              << item.product.getId() << '\n';

    return 0;
}