#include "Checkout.h"

Checkout::Checkout() : total(0){};

void Checkout::addItemPrice(std::string item, int price)
{
    prices[item] = price;
}

void Checkout::addItem(std::string item)
{
    std::map<std::string, int>::iterator priceIter = prices.find(item);
    if (priceIter == prices.end())
    {
        throw std::invalid_argument("Invalid item, No price");
    }
    items[item]++;
}

int Checkout::calculateTotal()
{
    total = 0;
    // count each item
    for (std::map<std::string, int>::iterator itemIter = items.begin(); itemIter != items.end(); itemIter++)
    {
        std::string item = itemIter->first;
        int itemCnt = itemIter->second;
        calculateItem(item, itemCnt);
    }
    return total;
}

void Checkout::calculateItem(std::string item, int itemCnt)
{
    std::map<std::string, Discount>::iterator discountIter;
    discountIter = discounts.find(item);
    // if there is a discount for this item, apply algorithm for it
    if (discountIter != discounts.end())
    {
        Discount discount = discountIter->second;
        calculateDiscount(item, itemCnt, discount);
    }
    else
    {
        total += itemCnt * prices[item];
    }
}

void Checkout::calculateDiscount(std::string item, int itemCnt, Discount discount)
{
    if (itemCnt >= discount.nbrOfItems)
    {
        int nbrOfDiscounts = itemCnt / discount.nbrOfItems; // 17/5 = 3.
        total += nbrOfDiscounts * discount.discountPrice;   // 3*price
        int remainingItems = itemCnt % discount.nbrOfItems; // 17/5 will leave 2 % modulo operator, gives the remainder after division
        total += remainingItems * prices[item];             // Discount will be applied only for 5, the other 2 will have the normal price
    }
    else
    {
        total += itemCnt * prices[item];
    }
}

void Checkout::addDiscount(std::string item, int nbrOfItems, int discountPrice)
{
    Discount discount;
    discount.nbrOfItems = nbrOfItems;
    discount.discountPrice = discountPrice;
    discounts[item] = discount;
}

Checkout::~Checkout(){
    //
};