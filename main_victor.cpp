#include <gtest/gtest.h>
// #include <cmath>

// First make the test fail, then work on it to work, keep it simple.
std::string fizzBuzz(int n)
{
    //  return "";
    if ((n % 3) == 0 && (n % 5) == 0)
    {
        return "FizzBuzz";
    }
    if ((n % 3) == 0)
    {
        return "Fizz";
    }
    else if ((n % 5) == 0)
    {
        return "Buzz";
    }
    else
    {
        return std::to_string(n);
    }
}
// 1. Call fizzBuzz
TEST(FizzBuzzTest, canCallFizzBuzz)
{
    std::string result = fizzBuzz(1);
}

// 2. Get 1 when I pass in 1.
TEST(fizzBuzzTest, get1)
{
    std::string result = fizzBuzz(1);
    ASSERT_TRUE(result == "1");
}

TEST(fizzBuzzTest, get2)
{
    std::string result = fizzBuzz(2);
    ASSERT_TRUE(result == "2");
}

// get Fizz when I pass in 3
TEST(fizzBuzzTest, getFizz)
{
    std::string result = fizzBuzz(3);
    ASSERT_TRUE(result == "Fizz");
}

// get Buzz when I pass in 5
TEST(fizzBuzzTest, getBuzz)
{
    std::string result = fizzBuzz(5);
    ASSERT_TRUE(result == "Buzz");
}

// Get Fizz when I pass multiple of 3
TEST(fizzBuzzTest, getFizz_Multiple3)
{
    std::string result = "";
    for (int i = 1; i < 2; ++i)
    {
        std::cout << "n:" << i << std::endl;
        result = fizzBuzz(i * 3);
        ASSERT_TRUE(result == "Fizz");
    }
}

// Get Fizz when I pass multiple of 3
TEST(fizzBuzzTest, getBuzz_Multiple5)
{
    std::string result = "";
    for (int i = 1; i < 2; ++i)
    {
        std::cout << "n:" << i << std::endl;
        result = fizzBuzz(i * 5);
        ASSERT_TRUE(result == "Buzz");
    }
}

// Get Fizz when I pass multiple of 3
TEST(fizzBuzzTest, getFizzBuzz_Multiple3_5)
{
    std::string result = "";
    result = fizzBuzz(15);
    ASSERT_TRUE(result == "FizzBuzz");
}