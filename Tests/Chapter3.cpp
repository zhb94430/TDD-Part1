#include <gtest/gtest.h>
#include "../Chapter3/Dollar.h"

TEST(CHAPTER3, Multiplication)
{
	Dollar five(5);
	Dollar product = five.times(2);

	ASSERT_EQ(10, product.amount);	

	product = five.times(3);

	ASSERT_EQ(15, product.amount);
}

TEST(CHAPTER3, Equality)
{
	ASSERT_TRUE(Dollar(5).equals(Dollar(5)));
	ASSERT_FALSE(Dollar(5).equals(Dollar(6)));
}