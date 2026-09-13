#include "../include/menu.h"
#include "../include/order.h"

#include <iostream>
#include <string>

using namespace std;

void addProduct(ProductManager& manager)
{
    int id;
    string name;
    double price;
    int stock;
    string category;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter Product Name: ";
    cin >> name;

    cout << "Enter Product Price: ";
    cin >> price;

    cout << "Enter Product Stock: ";
    cin >> stock;

    cout << "Enter Product Category: ";
    cin >> category;

    manager.addProduct(Product(id, name, price, stock, category));

    cout << "\nProduct added successfully!\n";
    manager.saveToFile("data/products.txt");
}

void removeProduct(ProductManager& manager)
{
    int id;

    cout << "\nEnter Product ID to remove: ";
    cin >> id;

    if (manager.removeProduct(id))
    {
        cout << "Product removed successfully!\n";
        manager.saveToFile("data/products.txt");
    }
    else
    {
        cout << "Product not found!\n";
    }
}

void searchProduct(ProductManager& manager)
{
    int id;

    cout << "\nEnter Product ID to search: ";
    cin >> id;

    Product* product = manager.findProduct(id);

    if (product)
        product->productDetails();
    else
        cout << "Product not found!\n";
}

void updatePrice(ProductManager& manager)
{
    int id;
    double newPrice;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter New Price: ";
    cin >> newPrice;

    manager.updateProductPrice(id, newPrice);
    manager.saveToFile("data/products.txt");
}

void updateStock(ProductManager& manager)
{
    int id;
    int newStock;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter New Stock: ";
    cin >> newStock;

    manager.updateProductStock(id, newStock);
    manager.saveToFile("data/products.txt");
}

void addToCart(ProductManager& manager, Cart& cart)
{
    int id;
    int quantity;

    cout << "\nEnter Product ID: ";
    cin >> id;

    Product* product = manager.findProduct(id);

    if (!product)
    {
        cout << "Product not found!\n";
        return;
    }

    cout << "Enter Quantity: ";
    cin >> quantity;

    cart.addItem(*product, quantity);
}

void removeFromCart(Cart& cart)
{
    int id;

    cout << "\nEnter Product ID to remove from cart: ";
    cin >> id;

    if (cart.removeItem(id))
        cout << "Product removed from cart successfully!\n";
    else
        cout << "Product not found in cart!\n";
}

void createOrder(ProductManager& manager, Cart& cart, int& nextOrderId)
{
    if (cart.getItems().empty())
    {
        cout << "\nCart is empty!\n";
        return;
    }

    Order order(nextOrderId++);

    for (const auto& item : cart.getItems())
    {
        order.addProduct(item);

        Product* product = manager.findProduct(item.product.getId());

        if (product)
            product->subtractStock(item.quantity);
    }

    order.calculateTotal();
    order.displayOrder();

    cart.clear();
    manager.saveToFile("data/products.txt");
}

void runMenu(ProductManager& manager, Cart& cart)
{
    int nextOrderId = 1001;
    int choice;

    while (true)
    {
        cout << "\n================================\n";
        cout << "           SHOPSYNC\n";
        cout << "================================\n";

        cout << "1. Add Product\n";
        cout << "2. Remove Product\n";
        cout << "3. Search Product\n";
        cout << "4. Update Price\n";
        cout << "5. Update Stock\n";
        cout << "6. Display Products\n";
        cout << "7. Sort By Price\n";
        cout << "8. Sort By Stock\n";
        cout << "9. Exit\n";
        cout << "10. Add product to cart\n";
        cout << "11. Display Cart\n";
        cout << "12. Remove Product from Cart\n";
        cout << "13. Calculate Cart Total\n";
        cout << "14. Create Order\n";
        cout << "15. Save Products to File\n";
        cout << "\nEnter choice: ";

        cin >> choice;

        switch (choice)
        {
            case 1:
                addProduct(manager);
                break;

            case 2:
                removeProduct(manager);
                break;

            case 3:
                searchProduct(manager);
                break;

            case 4:
                updatePrice(manager);
                break;

            case 5:
                updateStock(manager);
                break;

            case 6:
                manager.displayAllProducts();
                break;

            case 7:
                manager.sortByPrice();
                break;

            case 8:
                manager.sortByStock();
                break;

            case 9:
                cout << "Exiting ShopSync...\n";
                return;

            case 10:
                addToCart(manager, cart);
                break;

            case 11:
                cart.displayCart();
                break;

            case 12:
                removeFromCart(cart);
                break;

            case 13:
                cout << "\nCart Total: ₹" << cart.calculateTotal() << '\n';
                break;

            case 14:
                createOrder(manager, cart, nextOrderId);
                break;

            case 15:
                manager.saveToFile("data/products.txt");
                cout << "Products saved successfully!\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    }
}