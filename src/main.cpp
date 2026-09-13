
#include "../include/product_manager.h"
#include "../include/cart.h"
#include "../include/menu.h"

int main()
{
    ProductManager manager;
    Cart cart;

    manager.loadFromFile("data/products.txt");

    runMenu(manager, cart);

    return 0;
}
