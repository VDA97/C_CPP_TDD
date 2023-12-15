#ifndef DISCOUNTRULES_H_
#define DISCOUNTRULES_H_

/* Rules will be applied according with number of items*/

class DiscountRules
{
private:
    int m_percentage = 0;
    int m_newPrice = 0;
    int m_curPrice = 0;
    void applyRule(); // Defines the rule checking the number of items

public:
    DiscountRules(int price, int rule) : m_curPrice(price)
    {
        applyRule();
    };
    int getNewPrice() const { return m_newPrice; }
};

#endif /*DISCOUNTRULES_H_*/
