#include <gtest/gtest.h>

#include "../Chapter16/MoneyFactory.h"
#include "../Chapter16/Sum.h"
#include "../Chapter16/Bank.h"

// TEST(CHAPTER16, DollarMultiplication)
// {
// 	Money* five = MoneyFactory::dollar(5);

// 	ASSERT_EQ(*MoneyFactory::dollar(10), *five->times(2));	
// 	ASSERT_EQ(*MoneyFactory::dollar(15), *five->times(3));
// }

// TEST(CHAPTER16, FrancMultiplication)
// {
// 	Money* five = MoneyFactory::franc(5);

// 	ASSERT_EQ(*MoneyFactory::franc(10), *five->times(2));	
// 	ASSERT_EQ(*MoneyFactory::franc(15), *five->times(3));
// }

TEST(CHAPTER16, Equality)
{
	ASSERT_TRUE(*MoneyFactory::dollar(5) == *MoneyFactory::dollar(5));
	ASSERT_FALSE(*MoneyFactory::dollar(5) == *MoneyFactory::dollar(6));
	ASSERT_FALSE(*MoneyFactory::franc(5) == *MoneyFactory::dollar(5));
}

TEST(CHAPTER16, SimpleAddition)
{
	Money* five = MoneyFactory::dollar(5);
	Expression* sum = five->plus(five);
	Bank bank;

	Money* reduced = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(10), *reduced);
}

TEST(CHAPTER16, PlusReturnsSum)
{
	Money* five = MoneyFactory::dollar(5);
	Expression* result = five->plus(five);

	Sum* sum = dynamic_cast<Sum*>(result);

	ASSERT_TRUE(sum);

	ASSERT_EQ(five, sum->augend);
	ASSERT_EQ(five, sum->addend);
}

TEST(CHAPTER16, ReduceSum)
{
	Expression* sum = new Sum(MoneyFactory::dollar(3), MoneyFactory::dollar(4));
	Bank bank;
	
	Money* result = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(7), *result);
}

TEST(CHAPTER16, ReduceMoney)
{
	Bank bank;

	Money* result = bank.reduce(MoneyFactory::dollar(1), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(1), *result);
}

TEST(CHAPTER16, ReduceMoneyDifferentCurrency)
{
	Bank bank;

	bank.addRate("CHF", "USD", 2);
	Money* result = bank.reduce(MoneyFactory::franc(2), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(1), *result);
}

TEST(CHAPTER16, IdentityRate)
{
	Bank bank;

	ASSERT_EQ(1, bank.rate("USD", "USD"));
}

TEST(CHAPTER16, MixedAddition)
{
	Expression* fiveBucks = MoneyFactory::dollar(5);
	Expression* tenFrancs = MoneyFactory::franc(10);
	
	Bank bank;
	bank.addRate("CHF", "USD", 2);

	Money* result = bank.reduce(fiveBucks->plus(tenFrancs), "USD");

	ASSERT_EQ(*MoneyFactory::dollar(10), *result);
}

TEST(CHAPTER16, SumPlusMoney)
{
	Expression* fiveBucks = MoneyFactory::dollar(5);
	Expression* tenFrancs = MoneyFactory::franc(10);

	Bank bank;
	bank.addRate("CHF", "USD", 2);

	Expression* sum = new Sum(fiveBucks, tenFrancs);
	sum = sum->plus(fiveBucks);

	Money* result = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(15), *result);
}

TEST(CHAPTER16, SumTimes)
{
	Expression* fiveBucks = MoneyFactory::dollar(5);
	Expression* tenFrancs = MoneyFactory::franc(10);

	Bank bank;
	bank.addRate("CHF", "USD", 2);

	Expression* sum = new Sum(fiveBucks, tenFrancs);
	sum = sum->times(2);

	Money* result = bank.reduce(sum, "USD");

	ASSERT_EQ(*MoneyFactory::dollar(20), *result);
}


