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
