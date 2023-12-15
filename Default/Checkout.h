#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include <map>
#include <string>

class Checkout
{
public:
    Checkout();
    void addItemPrice(std::string item, int price);
    void addItem(std::string item);
    int calculateTotal();
    void addDiscount(std::string item, int nbrOfItems, int discountPrice);
    virtual ~Checkout();

protected:
    std::map<std::string, int> prices;
    int total;
};

#endif /*CHECKOUT_H_*/
