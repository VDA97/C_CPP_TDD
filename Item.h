#ifndef ITEM_H_
#define ITEM_H_

#include <string>

class Item
{
private:
    int price = 0;
    std::string name = "";

public:
    Item(std::string name, int price) : name(name), price(price){};
    int getPrice() { return price; }
    std::string getName() { return name; }
};

#endif /*ITEM_H_*/
