#include <gtest/gtest.h>
#include <iostream>
#include <memory>
#include "Checkout.h"
#include "Item.h"
#include "DiscountRules.h"

using namespace std;

TEST(CheckoutTests, CanInstantiateCheckout)
{
    shared_ptr<Checkout> co = make_shared<Checkout>();
}

TEST(CheckoutTests, CanInstantiateItem)
{
    shared_ptr<Item> item1 = make_shared<Item>("coca-cola", 10);
    EXPECT_EQ(item1->getName(), "coca-cola");
    ASSERT_TRUE(item1->getPrice() == 10);
}

TEST(CheckoutTests, CanAddItem)
{
    Item *item1 = new Item("coca-cola", 10);
    shared_ptr<Checkout> co = make_shared<Checkout>();
    co->addItem(item1);
}

TEST(CheckoutTests, CanGetItem)
{
    Item *item1 = new Item("coca-cola", 10);
    shared_ptr<Checkout> co = make_shared<Checkout>();
    co->addItem(item1);
    auto item = co->getItemByName("coca-cola");
    EXPECT_EQ(item.getName(), "coca-cola");
}

TEST(CheckoutTests, CanGetItemsPrice)
{
    Item *item1 = new Item("coca-cola", 10);
    Item *item2 = new Item("pepsi", 12);
    shared_ptr<Checkout> co = make_shared<Checkout>();
    co->addItem(item1);
    co->addItem(item2);
    ASSERT_TRUE(co->getTotalPrice() == (item1->getPrice() + item2->getPrice()));
}

TEST(CheckoutTests, CanApplyDiscountRule)
{
    Item *item1 = new Item("coca-cola", 10);
    Item *item2 = new Item("pepsi", 12);
    shared_ptr<Checkout> co = make_shared<Checkout>();
    co->addItem(item1);
    co->addItem(item2);
    float item12 = (item1->getPrice() + item2->getPrice()) * 0.80;
    ASSERT_TRUE(co->applyDiscount(1) == item12);
}
