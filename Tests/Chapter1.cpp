#include <gtest/gtest.h>
#include <Dollar.h>

TEST(CHAPTER1, Multiplication)
{
	Dollar five = new Dollar(5);
	five.times(2);

	ASSERT_EQ(10, five.amount);	
}