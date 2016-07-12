//
// Created by Tamas Karpati on 2016-07-12.
//

#include "gmock/gmock.h"
#include "Make.h"

struct test_data
{
    test_data() = default;
    test_data(const test_data&) = delete;
    test_data(test_data&&) = default;

    explicit test_data(int a)
        : sum(a)
    {}

    test_data(int a, double b)
        : sum(a + static_cast<int>(b))
    {}

    test_data(int a, int b, const test_data& c)
        : sum(a + b + c.sum)
    {}

    int sum = 123;
};

TEST(MakeTests, MakeObjectNoArguments)
{
    auto&& test = bounty::make<test_data>();
    EXPECT_EQ(123, test.sum);
}

TEST(MakeTests, MakeObjectOneArgument)
{
    auto&& test = bounty::make<test_data>(1);
    EXPECT_EQ(1, test.sum);
}

TEST(MakeTests, MakeObjectTwoArguments)
{
    auto&& test = bounty::make<test_data>(1, 2.0);
    EXPECT_EQ(3, test.sum);
}

TEST(MakeTests, MakeObjectThreeArguments)
{
    test_data test123;
    auto&& test = bounty::make<test_data>(1, 2, test123);
    EXPECT_EQ(126, test.sum);
}