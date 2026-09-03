#include "../include/product.h"
#include <iostream>
using namespace std;

int main()
{
    Product laptop(101,"Laptop",55000.0,10,"Electronics");
    cout << "Initial Product:\n";
    laptop.productDetails();
    cout << "\nAfter adding 5 units:\n";
    laptop.addStock(5);
    laptop.productDetails();

    cout << "\nSelling 3 units:\n";

if (laptop.subtractStock(3)) {cout<< "Sale successful.\n";}
else {cout << "Sale failed.\n";}
laptop.productDetails();
cout << "\nPrice after 10\% discount: "<< laptop.discountPrice(10)<< '\n';

    return 0;
}