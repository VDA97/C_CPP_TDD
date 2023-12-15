#include "Checkout.h"

Checkout::Checkout() : total(0){};

void Checkout::addItemPrice(std::string item, int price)
{
    prices[item] = price;
}

void Checkout::addItem(std::string item)
{
    total += prices[item];
}

int Checkout::calculateTotal()
{
    return total;
}

void Checkout::addDiscount(std::string item, int nbrOfItems, int discountPrice)
{
    // Todo
}

Checkout::~Checkout(){
    //
};