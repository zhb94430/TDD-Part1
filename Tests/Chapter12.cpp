#include <gtest/gtest.h>
#include "../Chapter12/Money.h"
#include "../Chapter12/MoneyFactory.h"
#include "../Chapter12/Bank.h"

TEST(CHAPTER12, DollarMultiplication)
{
	Money five = MoneyFactory::dollar(5);

	ASSERT_EQ(MoneyFactory::dollar(10), five * 2);	
	ASSERT_EQ(MoneyFactory::dollar(15), five * 3);
}

TEST(CHAPTER12, FrancMultiplication)
{
	Money five = MoneyFactory::franc(5);

	ASSERT_EQ(MoneyFactory::franc(10), five * 2);	
	ASSERT_EQ(MoneyFactory::franc(15), five * 3);
}

TEST(CHAPTER12, Equality)
{
	ASSERT_TRUE(MoneyFactory::dollar(5) == MoneyFactory::dollar(5));
	ASSERT_FALSE(MoneyFactory::dollar(5) == MoneyFactory::dollar(6));
	ASSERT_FALSE(MoneyFactory::franc(5) == MoneyFactory::dollar(5));
}

TEST(CHAPTER12, SimpleAddition)
{
	Money five = MoneyFactory::dollar(5);
	Expression sum = five.plus(five);
	Bank bank;

	Money reduced = bank.reduce(five, "USD");

	ASSERT_EQ(MoneyFactory::dollar(10), reduced);
}