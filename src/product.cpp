#include "../include/product.h"
#include <iostream>
using namespace std;
#include <iomanip>
//constructor
Product::Product(int id,const string& name,double price,int stock,const string& category): id(id), name(name),
 price(price),stock(stock),category(category){  }

//addstock
void Product::addStock(int quantity){
    if (quantity > 0) { stock += quantity;}}

//substock
bool Product::subtractStock(int quantity)
{
    if (quantity <= 0 || quantity > stock) {
        return false;
    } stock -= quantity;
    return true;
}
//discount price
double Product::discountPrice(double percentage) const
{
    if (percentage < 0 || percentage > 100) {
        return price;}

    return price - (price * percentage / 100);
}
//details
void Product::productDetails() const
{
    std::cout << "Product ID : " << id << '\n';
    std::cout << "Name       : " << name << '\n';
    std::cout << "Price      : " << fixed << setprecision(2) << price << '\n';
    std::cout << "Stock      : " << stock << '\n';
    std::cout << "Category   : " << category << '\n';
}
int Product::getId() const
{
    return id;
}