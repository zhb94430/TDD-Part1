#include <gtest/gtest.h>

#include "../Chapter15/MoneyFactory.h"
#include "../Chapter15/Sum.h"
#include "../Chapter15/Bank.h"

// TEST(CHAPTER15, DollarMultiplication)
// {
// 	Money* five = MoneyFactory::dollar(5);

// 	ASSERT_EQ(*MoneyFactory::dollar(10), *five->times(2));	
// 	ASSERT_EQ(*MoneyFactory::dollar(15), *five->times(3));
// }

// TEST(CHAPTER15, FrancMultiplication)
// {
// 	Money* five = MoneyFactory::franc(5);

// 	ASSERT_EQ(*MoneyFactory::franc(10), *five->times(2));	
// 	ASSERT_EQ(*MoneyFactory::franc(15), *five->times(3));
// }

TEST(CHAPTER15, Equality)
{
	ASSERT_TRUE(*MoneyFactory::dollar(5) == *MoneyFactory::dollar(5));
	ASSERT_FALSE(*MoneyFactory::dollar(5) == *MoneyFactory::dollar(6));
	ASSERT_FALSE(*MoneyFactory::franc(5) == *MoneyFactory::dollar(5));
}

TEST(CHAPTER15, SimpleAddition)
{
	Money* five = MoneyFactory::dollar(5);
	Expression* sum = five->plus(five);
	Bank bank;

	Money* reduced = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(10), *reduced);
}

TEST(CHAPTER15, PlusReturnsSum)
{
	Money* five = MoneyFactory::dollar(5);
	Expression* result = five->plus(five);

	Sum* sum = dynamic_cast<Sum*>(result);

	ASSERT_TRUE(sum);

	ASSERT_EQ(five, sum->augend);
	ASSERT_EQ(five, sum->addend);
}

TEST(CHAPTER15, ReduceSum)
{
	Expression* sum = new Sum(MoneyFactory::dollar(3), MoneyFactory::dollar(4));
	Bank bank;
	
	Money* result = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(7), *result);
}

TEST(CHAPTER15, ReduceMoney)
{
	Bank bank;

	Money* result = bank.reduce(MoneyFactory::dollar(1), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(1), *result);
}

TEST(CHAPTER15, ReduceMoneyDifferentCurrency)
{
	Bank bank;

	bank.addRate("CHF", "USD", 2);
	Money* result = bank.reduce(MoneyFactory::franc(2), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(1), *result);
}

TEST(CHAPTER15, IdentityRate)
{
	Bank bank;

	ASSERT_EQ(1, bank.rate("USD", "USD"));
}

TEST(CHAPTER15, MixedAddition)
{
	Expression* fiveBucks = MoneyFactory::dollar(5);
	Expression* tenFrancs = MoneyFactory::franc(10);
	
	Bank bank;
	bank.addRate("CHF", "USD", 2);

	Money* result = bank.reduce(fiveBucks->plus(tenFrancs), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(10), *result);

}