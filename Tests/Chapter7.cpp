#include <gtest/gtest.h>
#include "../Chapter7/Dollar.h"
#include "../Chapter7/Franc.h"
#include "../Chapter7/Money.h"

TEST(CHAPTER7, DollarMultiplication)
{
	Dollar five(5);

	ASSERT_EQ(Dollar(10), five * 2);	
	ASSERT_EQ(Dollar(15), five * 3);
}

TEST(CHAPTER7, FrancMultiplication)
{
	Franc five(5);

	ASSERT_EQ(Franc(10), five * 2);	
	ASSERT_EQ(Franc(15), five * 3);
}

TEST(CHAPTER7, Equality)
{
	ASSERT_TRUE(Dollar(5) == Dollar(5));
	ASSERT_FALSE(Dollar(5) == Dollar(6));

	ASSERT_TRUE(Franc(5) == Franc(5));
	ASSERT_FALSE(Franc(5) == Franc(6));

	ASSERT_FALSE(Franc(5) == Dollar(5));
}