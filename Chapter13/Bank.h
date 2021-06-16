#pragma once

#include "MoneyFactory.h"
#include "Expression.h"

class Bank
{
public:
	Money& reduce(Expression& source, std::string to)
	{
		Sum& sum = dynamic_cast<Sum&>(source);

		int amount = sum.augend.amount + sum.addend.amount;

		return *(new Money(amount, to));
	}
};