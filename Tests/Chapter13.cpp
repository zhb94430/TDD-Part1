#include <gtest/gtest.h>

#include "../Chapter13/MoneyFactory.h"
#include "../Chapter13/Sum.h"
#include "../Chapter13/Bank.h"

TEST(CHAPTER13, DollarMultiplication)
{
	Money* five = MoneyFactory::dollar(5);

	ASSERT_EQ(*MoneyFactory::dollar(10), *five->times(2));	
	ASSERT_EQ(*MoneyFactory::dollar(15), *five->times(3));
}

TEST(CHAPTER13, FrancMultiplication)
{
	Money* five = MoneyFactory::franc(5);

	ASSERT_EQ(*MoneyFactory::franc(10), *five->times(2));	
	ASSERT_EQ(*MoneyFactory::franc(15), *five->times(3));
}

TEST(CHAPTER13, Equality)
{
	ASSERT_TRUE(*MoneyFactory::dollar(5) == *MoneyFactory::dollar(5));
	ASSERT_FALSE(*MoneyFactory::dollar(5) == *MoneyFactory::dollar(6));
	ASSERT_FALSE(*MoneyFactory::franc(5) == *MoneyFactory::dollar(5));
}

TEST(CHAPTER13, SimpleAddition)
{
	Money* five = MoneyFactory::dollar(5);
	Expression* sum = five->plus(five);
	Bank bank;

	Money* reduced = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(10), *reduced);
}

TEST(CHAPTER13, PlusReturnsSum)
{
	Money* five = MoneyFactory::dollar(5);
	Expression* result = five->plus(five);

	Sum* sum = dynamic_cast<Sum*>(result);

	ASSERT_TRUE(sum);

	ASSERT_EQ(five, sum->augend);
	ASSERT_EQ(five, sum->addend);
}

TEST(CHAPTER13, ReduceSum)
{
	Expression* sum = new Sum(MoneyFactory::dollar(3), MoneyFactory::dollar(4));
	Bank bank;
	
	Money* result = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(7), *result);
}

TEST(CHAPTER13, ReduceMoney)
{
	Bank bank;

	Money* result = bank.reduce(MoneyFactory::dollar(1), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(1), *result);
}