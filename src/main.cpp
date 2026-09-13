#include "../include/product_manager.h"
#include <iostream>
#include "../include/cart.h"
#include "../include/order.h"
using namespace std;

int main()
{
    ProductManager manager;
    manager.loadFromFile("data/products.txt");
    Cart cart;
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
    cout<< "10. Add product to cart \n";
    cout << "11. Display Cart\n";
    cout << "12. Remove Product from Cart\n";
    cout << "13. Calculate Cart Total\n";
    cout<< " 14. create order \n";
    cout << "15. Save Products to File\n";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (choice == 9)
    {
        cout << "Exiting ShopSync...\n";
        break;
    }

if (choice == 1)
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
if (choice == 2)
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
if (choice == 3)
{
    string name;

    cout << "\nEnter Product Name to search: ";
    cin >> name;

    Product* product = manager.findProductByName(name);

    if (product != nullptr)
    {
        cout << "\nProduct Found!\n";
        cout << "-------------------------\n";
        product->productDetails();
    }
    else
    {
        cout << "Product not found!\n";
    }
}
if (choice == 4)
{
    int id;
    double newPrice;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter New Price: ";
    cin >> newPrice;

    Product* product = manager.findProduct(id);

    if (product != nullptr)
    {
        product->updatePrice(newPrice);
        manager.saveToFile("data/products.txt");
        cout << "Price updated successfully!\n";
    }
    else
    {
        cout << "Product not found!\n";
    }
}
if (choice == 5)
{
    int id;
    int newStock;

    cout << "\nEnter Product ID: ";
    cin >> id;

    cout << "Enter New Stock: ";
    cin >> newStock;

    Product* product = manager.findProduct(id);

    if (product != nullptr)
    {
        product->updateStock(newStock);
        manager.saveToFile("data/products.txt");
        cout << "Stock updated successfully!\n";
    }
    else
    {
        cout << "Product not found!\n";
    }
}

if (choice == 6){
    cout << "\n========== ALL PRODUCTS ==========\n";
    manager.displayAllProducts();}
if (choice == 7)
{
    cout << "\nProducts sorted by price:\n";

    manager.sortByPrice();

}
if (choice == 8)
{
    cout << "\nProducts sorted by stock:\n";

    manager.sortByStock();

}
if (choice == 10)
{
    string name;
    int quantity;

    cout << "\nEnter Product Name to add to cart: ";
    cin >> name;

    cout << "Enter Quantity: ";
    cin >> quantity;

    Product* product = manager.findProductByName(name);

    if (product != nullptr)
    {
        cart.addItem(*product, quantity);
        cout << "Product added to cart successfully!\n";
    }
    else
    {
        cout << "Product not found!\n";
    }
}
if (choice == 11)
{
    cout << "\n========== YOUR CART ==========\n";

    cart.displayCart();
}
if (choice == 12)
{
    string name;

    cout << "\nEnter Product Name to remove from cart: ";
    cin >> name;

    Product* product = manager.findProductByName(name);

    if (product != nullptr)
    {
        if (cart.removeItem(product->getId()))
        {
            cout << "Product removed from cart successfully!\n";
        }
        else
        {
            cout << "Product is not in the cart!\n";
        }
    }
    else
    {
        cout << "Product not found!\n";
    }
}
if (choice == 13)
{
    double total = cart.calculateTotal();

    cout << "\n========== CART TOTAL ==========\n";
    cout << "Total Amount: " << total << '\n';
}
if (choice == 14)
{
    cout << "\nCreating order...\n";

    const vector<CartItem>& cartItems = cart.getItems();

    if (cartItems.empty())
    {
        cout << "Cart is empty! Cannot create order.\n";
    }
    else
    {
        // Step 1: Check current stock for every item
        bool stockAvailable = true;

        for (const CartItem& item : cartItems)
        {
            Product* product = manager.findProduct(item.product.getId());

            if (product == nullptr ||
                product->getStock() < item.quantity)
            {
                cout << "Insufficient stock for Product ID: "
                     << item.product.getId() << '\n';

                stockAvailable = false;
                break;
            }
        }

        // Step 2: Only continue if ALL products are available
        if (stockAvailable)
        {  Order order(nextOrderId);
            for (const CartItem& item : cartItems)
            {
                Product* product =
                    manager.findProduct(item.product.getId());

                product->subtractStock(item.quantity);

                order.addProduct(item);
            }

            // Step 3: Calculate order total
            order.calculateTotal();
            //save updated stock to file
            manager.saveToFile("data/products.txt");

            // Step 4: Confirm order
            cout << "Order created successfully!\n";

            order.displayOrder();
            nextOrderId++;

            // Step 5: Empty cart
            cart.clear();

            cout << "Cart cleared successfully!\n";
        }
        
    }
}
if (choice == 15)
{
    manager.saveToFile("data/products.txt");
}
}

    return 0;
}