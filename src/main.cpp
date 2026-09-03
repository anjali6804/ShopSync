#include "../include/product_manager.h"
#include <iostream>
using namespace std;

int main()
{
    ProductManager manager;

    // Add products
    manager.addProduct( Product(101, "Laptop", 55000.0, 10, "Electronics"));

    manager.addProduct(Product(102, "Mouse", 800.0, 20, "Accessories"));

    manager.addProduct( Product(103, "Keyboard", 1500.0, 15, "Accessories"));

    // Display all products
    cout << "===== ALL PRODUCTS =====\n";
    manager.displayAllProducts();

    // Search product
    cout << "\n===== SEARCH PRODUCT =====\n";
    Product* found = manager.findProduct(102);

    if (found != nullptr)
    {
        cout << "Product found:\n";
        found->productDetails();
    }
    else
    {
        cout << "Product not found.\n";
    }

    // Remove product
    cout << "\n===== REMOVE PRODUCT =====\n";

    if (manager.removeProduct(102))
    {
        cout << "Product removed successfully.\n";
    }
    else
    {
        cout << "Product not found.\n";
    }

    // Display after removal
    cout << "\n===== PRODUCTS AFTER REMOVAL =====\n";
    manager.displayAllProducts();

    return 0;
}