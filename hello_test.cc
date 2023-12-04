#include <gtest/gtest.h>
#include "hello_world.hpp"

TEST(HelloTest, TestBasicFunction)
{
    EXPECT_EQ(hello_world(), "hello world cmake");
}

TEST(BasicAssertion, MathAssertion)
{
    EXPECT_EQ(7 * 6, 42);
}