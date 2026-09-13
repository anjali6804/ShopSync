#include "../include/product_manager.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <sstream>
#include <cctype>

void ProductManager::addProduct(const Product& product)
{
     products.emplace(product.getId(), product);
}

bool ProductManager::removeProduct(int id)
{
    return products.erase(id) > 0;
}

Product* ProductManager::findProduct(int id)
{
    auto it = products.find(id);

    if (it != products.end())
    {
        return &it->second;
    }

    return nullptr;
}
Product* ProductManager::findProductByName(const std::string& name)
{
    for (auto& pair : products)
    {
        std::string productName = pair.second.getName();

        if (productName.size() == name.size())
        {
            bool match = true;

            for (size_t i = 0; i < name.size(); i++)
            {
                if (std::tolower(productName[i]) != std::tolower(name[i]))
                {
                    match = false;
                    break;
                }
            }

            if (match)
            {
                return &pair.second;
            }
        }
    }

    return nullptr;
}
void ProductManager::displayAllProducts() const
{
    for (const auto& pair : products)
    {
        pair.second.productDetails();
        std::cout << "-------------------------\n";
    }
}

void ProductManager::updateProductPrice(int id, double newPrice)
{
    Product* product = findProduct(id);

    if (product != nullptr)
    {
        product->updatePrice(newPrice);
    }
}

void ProductManager::updateProductStock(int id, int newStock)
{
    Product* product = findProduct(id);

    if (product != nullptr)
    {
        product->updateStock(newStock);
    }
}

void ProductManager::sortByPrice()
{
    std::vector<Product> sortedProducts;

    for (const auto& pair : products)
    {
        sortedProducts.push_back(pair.second);
    }

    std::sort(sortedProducts.begin(), sortedProducts.end(),
              [](const Product& a, const Product& b)
              {
                  return a.getPrice() < b.getPrice();
              });

    for (const Product& product : sortedProducts)
    {
        product.productDetails();
        std::cout << "-------------------------\n";
    }
}

void ProductManager::sortByStock()
{
    std::vector<Product> sortedProducts;

    for (const auto& pair : products)
    {
        sortedProducts.push_back(pair.second);
    }

    std::sort(sortedProducts.begin(), sortedProducts.end(),
              [](const Product& a, const Product& b)
              {
                  return a.getStock() < b.getStock();
              });

    for (const Product& product : sortedProducts)
    {
        product.productDetails();
        std::cout << "-------------------------\n";
    }
}
void ProductManager::saveToFile(const std::string& filename) const
{
    std::ofstream file(filename);

    if (!file)
    {
        std::cout << "Error opening file!\n";
        return;
    }

    for (const auto& pair : products)
    {
        const Product& product = pair.second;

        file << product.getId() << '|'
             << product.getName() << '|'
             << product.getPrice() << '|'
             << product.getStock() << '|'
             << product.getCategory()
             << '\n';
    }

    file.close();

    std::cout << "Products saved successfully!\n";
}
void ProductManager::loadFromFile(const std::string& filename)
{
    std::ifstream file(filename);

    if (!file)
    {
        std::cout << "Error opening file!\n";
        return;
    }

    products.clear();

    std::string line;

    while (std::getline(file, line))
    {
        std::stringstream ss(line);

        std::string idStr;
        std::string name;
        std::string priceStr;
        std::string stockStr;
        std::string category;

        std::getline(ss, idStr, '|');
        std::getline(ss, name, '|');
        std::getline(ss, priceStr, '|');
        std::getline(ss, stockStr, '|');
        std::getline(ss, category, '|');

        int id = std::stoi(idStr);
        double price = std::stod(priceStr);
        int stock = std::stoi(stockStr);

        Product product(id, name, price, stock, category);

        products.emplace(id, product);
    }

    file.close();

    std::cout << "Products loaded successfully!\n";
}