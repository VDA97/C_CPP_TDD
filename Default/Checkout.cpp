#include "Checkout.h"

Checkout::Checkout(){
    //
};

void Checkout::addItem(Item *item)
{
    items.push_back(std::move(*item));
};

Item &Checkout::getItemByName(const std::string &name)
{
    auto itemIt = std::find_if(items.begin(), items.end(), [&name](Item &item)
                               { return item.getName() == name; });

    if (itemIt != items.end())
    {
        return *itemIt; // Return the reference to the found item
    }
    else
    {
        Item *item = new Item("null", 0);
        item = nullptr;
        return *item;
    }
}

int Checkout::getTotalPrice()
{
    return std::accumulate(items.begin(), items.end(), 0,
                           [](int sum, Item &item)
                           { return sum + item.getPrice(); });
}

float Checkout::applyDiscount(int rule)
{
    switch (rule)
    {
    case 1:
    {
        return getTotalPrice() * 0.8;
    }
    break;

    default:
        break;
    }
}

Checkout::~Checkout(){
    //
};