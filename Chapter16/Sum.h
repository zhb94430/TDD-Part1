#pragma once

#include "Expression.h"
#include "Money.h"

class Sum : public Expression
{
public:
	Expression* augend;
	Expression* addend;

	Sum(Expression* _augend, Expression* _addend)
	{ augend = _augend; addend = _addend; };

	Expression* plus(Expression* addend) 
	{ return new Sum(this, addend); };

	Expression* times(int multiplier)
	{ return new Sum(augend->times(multiplier), addend->times(multiplier)); };

	Money* reduce(Bank* bank, std::string to)
	{
		int amount = augend->reduce(bank, to)->amount 
				   + addend->reduce(bank, to)->amount;
		return new Money(amount, to);
	}
};