#include "NonNull.h"
#include "gtest/gtest.h"

#include <memory>

struct test_data
{
    int a = 5;
    int test()
    {
        return a;
    }
};

TEST(NonNullTests, AssertIfNotPointer)
{
    // This won't compile since 'int' is not a pointer type
    //bounty::non_null<int> test{ 5 };
}

TEST(NonNullTests, RawPointer_MemberAccess)
{
    test_data td;

    bounty::non_null<test_data*> test{ &td };
    ASSERT_EQ(td.a, test->test());
}

TEST(NonNullTests, SharedPointer_MemberAccess)
{
    auto&& td = std::make_shared<test_data>();

    bounty::non_null<std::shared_ptr<test_data>> test{ td };
    ASSERT_EQ(td->a, test->test());
}

TEST(NonNullTests, RawPointer_Dereference)
{
    test_data td;

    bounty::non_null<test_data*> test{ &td };
    ASSERT_EQ(td.a, (*test).a);
}

TEST(NonNullTests, RawPointer_NullptrInit)
{
    // This won't compile because nullptr init is prohibited
    //bounty::non_null<int*> test{ nullptr };
}

TEST(NonNullTests, RawPointer_NullptrAssign)
{
    test_data td;
    bounty::non_null<test_data*> test{ &td };

    EXPECT_DEATH(test = reinterpret_cast<test_data*>(0), "Assertion failed: o");
}

TEST(NonNullTests, SharedPointer_NullptrAssign)
{
    auto&& td = std::make_shared<test_data>();
    bounty::non_null<std::shared_ptr<test_data>> test{ td };

    EXPECT_DEATH(test = std::make_shared<test_data>(), "Assertion failed: o");
}

TEST(NonNullTests, RawPointer_NullptrTAssign)
{
    test_data td;
    bounty::non_null<test_data*> test{ &td };

    // This won't compile because nullptr cannot be assigned
    //test = nullptr;
}

TEST(NonNullTests, RawPointer_IndirectNullptrInit)
{
    int *a = nullptr;
    EXPECT_DEATH(bounty::non_null<int*>{ a }, "Assertion failed: ptr");
}

int main(int argc, char** argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    auto result = RUN_ALL_TESTS();
    getchar();
    return result;
}