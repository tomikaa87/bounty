//
// Created by Tamas Karpati on 2016-07-12.
//

#include "gmock/gmock.h"
#include "VariadicSum.h"

TEST(VariadicSumTests, OnlyOneInteger)
{
    EXPECT_EQ(1, bounty::variadic_sum(1));
}

TEST(VariadicSumTests, AddIntegers)
{
    EXPECT_EQ(2, bounty::variadic_sum(1, 1));
}

TEST(VariadicSumTests, AddFloats)
{
    EXPECT_EQ(2.0f, bounty::variadic_sum(1.0f, 1.0f));
}

TEST(VariadicSumTests, AddDoubles)
{
    EXPECT_EQ(2.0, bounty::variadic_sum(1.0, 1.0));
}

TEST(VariadicSumTests, AddVarious)
{
    EXPECT_EQ(3.0, bounty::variadic_sum(1.0, 1, 1.0f));
}

TEST(VariadicSumTests, AddMoreVarious)
{
    EXPECT_EQ(4.0, bounty::variadic_sum(1.0, 1, 1.0f, -1, 1u, 0x1));
}

TEST(VariadicSumTests, AddBool)
{
    EXPECT_EQ(2, bounty::variadic_sum(1, true));
}

TEST(VariadicSumTests, AddStruct)
{
    struct test_data
    {
        test_data& operator+(const test_data& rhs)
        {
            sum += rhs.sum;
            return *this;
        }

        test_data& operator+(int rhs)
        {
            sum += rhs;
            return *this;
        }

        operator int() const
        {
            return sum;
        }

        int sum = 0;
    } test;

    test.sum = 10;

    EXPECT_EQ(11, bounty::variadic_sum(test, 1));
}
