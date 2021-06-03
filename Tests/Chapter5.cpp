#include <gtest/gtest.h>
#include "../Chapter5/Dollar.h"
#include "../Chapter5/Franc.h"

TEST(CHAPTER5, DollarMultiplication)
{
	Dollar five(5);

	ASSERT_EQ(Dollar(10), five * 2);	
	ASSERT_EQ(Dollar(15), five * 3);
}

TEST(CHAPTER5, FrancMultiplication)
{
	Franc five(5);

	ASSERT_EQ(Franc(10), five * 2);	
	ASSERT_EQ(Franc(15), five * 3);
}

TEST(CHAPTER5, Equality)
{
	ASSERT_TRUE(Dollar(5) == Dollar(5));
	ASSERT_FALSE(Dollar(5) == Dollar(6));
}