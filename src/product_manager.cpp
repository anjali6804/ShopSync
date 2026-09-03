#include "../include/product_manager.h"
#include <iostream>

void ProductManager::addProduct(const Product& product)
{
    products.push_back(product);
}

bool ProductManager::removeProduct(int id)
{
    for (auto it = products.begin(); it != products.end(); ++it)
    {
        if (it->getId() == id)
        {
            products.erase(it);
            return true;
        }
    }

    return false;
}

Product* ProductManager::findProduct(int id)
{
    for (auto& product : products)
    {
        if (product.getId() == id)
        {
            return &product;
        }
    }

    return nullptr;
}

void ProductManager::displayAllProducts() const
{
    for (const Product& product : products)
    {
        product.productDetails();
        std::cout << "-------------------------\n";
    }
}