#include <gtest/gtest.h>
#include "../Chapter4/Dollar.h"

TEST(CHAPTER4, Multiplication)
{
	Dollar five(5);

	ASSERT_EQ(Dollar(10), five * 2);	
	ASSERT_EQ(Dollar(15), five * 3);
}

TEST(CHAPTER4, Equality)
{
	ASSERT_TRUE(Dollar(5) == Dollar(5));
	ASSERT_FALSE(Dollar(5) == Dollar(6));
}