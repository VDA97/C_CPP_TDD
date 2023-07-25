#include <gtest/gtest.h>
// #include <cmath>

// First make the test fail, then work on it to work, keep it simple. (Red phase)
// Second, check if we should refactor our test code

bool isMultiple(int value, int base)
{
    return (0 == (value % base));
}
std::string fizzBuzz(int value)
{
    if (isMultiple(value, 3) && isMultiple(value, 5))
        return "FizzBuzz";
    if (isMultiple(value, 3))
        return "Fizz";
    if (isMultiple(value, 5))
        return "Buzz";
    return std::to_string(value);
}

// Refactor, because we are calling fizBuzz in the second Test case.
/* TEST(FizzBuzzTest, canCallFizzBuzz)
{
    std::string result = fizzBuzz(1);
} */
void checkFizzBuzz(int value, std::string expectedResult)
{
    std::string result = fizzBuzz(value);
    ASSERT_STREQ(expectedResult.c_str(), result.c_str());
}

TEST(FizzBuzzTests, returns1With1PassedIn)
{
    checkFizzBuzz(1, "1");
}

TEST(FizzBuzzTests, returns2With2PassedIn)
{
    checkFizzBuzz(2, "2");
}

TEST(FizzBuzzTests, returnsFizzWith3PassedIn)
{
    checkFizzBuzz(3, "Fizz");
}

TEST(FizzBuzzTests, returnsBuzzWith5PassedIn)
{
    checkFizzBuzz(5, "Buzz");
}

TEST(FizzBuzzTests, returnsFizzWith_6_Multiple_of_3_PassedIn)
{
    checkFizzBuzz(6, "Fizz");
}

TEST(FizzBuzzTests, returnsBuzzWith_10_Multiple_of_5_PassedIn)
{
    checkFizzBuzz(10, "Buzz");
}

TEST(FizzBuzzTests, returnsBuzzWith_15_Multiple_of_3and5_PassedIn)
{
    checkFizzBuzz(15, "FizzBuzz");
}