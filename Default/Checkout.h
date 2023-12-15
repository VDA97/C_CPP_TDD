#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include "Item.h"

class Checkout
{
private:
    std::vector<Item> items;
    Item *item;

public:
    Checkout();
    void addItem(Item *item);
    Item &getItemByName(const std::string &name);
    int getTotalPrice();
    float applyDiscount(int rule);
    virtual ~Checkout();
};

#endif /*CHECKOUT_H_*/
