#include <gtest/gtest.h>
#include "../Chapter6/Dollar.h"
#include "../Chapter6/Franc.h"
#include "../Chapter6/Money.h"

TEST(CHAPTER6, DollarMultiplication)
{
	Dollar five(5);

	ASSERT_EQ(Dollar(10), five * 2);	
	ASSERT_EQ(Dollar(15), five * 3);
}

TEST(CHAPTER6, FrancMultiplication)
{
	Franc five(5);

	ASSERT_EQ(Franc(10), five * 2);	
	ASSERT_EQ(Franc(15), five * 3);
}

TEST(CHAPTER6, Equality)
{
	ASSERT_TRUE(Dollar(5) == Dollar(5));
	ASSERT_FALSE(Dollar(5) == Dollar(6));

	ASSERT_TRUE(Franc(5) == Franc(5));
	ASSERT_FALSE(Franc(5) == Franc(6));
}