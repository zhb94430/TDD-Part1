#include <gtest/gtest.h>
#include "../Chapter9/Dollar.h"
#include "../Chapter9/Franc.h"
#include "../Chapter9/Money.h"
#include "../Chapter9/MoneyFactory.h"

TEST(CHAPTER9, DollarMultiplication)
{
	Money* five = MoneyFactory::dollar(5);

	ASSERT_EQ(*(MoneyFactory::dollar(10)), *five * 2);	
	ASSERT_EQ(*(MoneyFactory::dollar(15)), *five * 3);
}

TEST(CHAPTER9, FrancMultiplication)
{
	Money* five = MoneyFactory::franc(5);

	ASSERT_EQ(*(MoneyFactory::franc(10)), *five * 2);	
	ASSERT_EQ(*(MoneyFactory::franc(15)), *five * 3);
}

TEST(CHAPTER9, Equality)
{
	ASSERT_TRUE(*(MoneyFactory::dollar(5)) == *(MoneyFactory::dollar(5)));
	ASSERT_FALSE(*(MoneyFactory::dollar(5)) == *(MoneyFactory::dollar(6)));

	ASSERT_TRUE(*(MoneyFactory::franc(5)) == *(MoneyFactory::franc(5)));
	ASSERT_FALSE(*(MoneyFactory::franc(5)) == *(MoneyFactory::franc(6)));

	ASSERT_FALSE(*(MoneyFactory::franc(5)) == *(MoneyFactory::dollar(5)));
}