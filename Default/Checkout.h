#ifndef CHECKOUT_H_
#define CHECKOUT_H_

#include <vector>
#include <string>
#include <algorithm>
#include <stdexcept>
#include <numeric>

class Checkout
{

public:
    Checkout();
    void addItemPrice(std::string item, int price);
    void addItem(std::string item);
    virtual ~Checkout();
};

#endif /*CHECKOUT_H_*/
