#include <gtest/gtest.h>
#include "../Chapter1/Dollar.h"

TEST(CHAPTER1, Multiplication)
{
	Dollar five(5);
	five.times(2);

	ASSERT_EQ(10, five.amount);	
}