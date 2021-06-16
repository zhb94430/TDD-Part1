#pragma once

#include <string>

#include "Expression.h"

class Money : public Expression
{
public:
	int amount;
	std::string currency; // Added since C++ does not have a getClass() equivalent


	Money() {};
	Money(int _amount, std::string _currency)
	{
		amount = _amount;
		currency = _currency;
	}


	bool operator==(const Money& other) const 
	{ 
		return amount == other.amount &&
			   currency == other.currency; 
	};
	
	Money& times(int multiplier) 
	{ return *(new Money(amount * multiplier, currency)); };

	Expression& plus(Money addend);

	std::string getCurrency()
	{
		return currency;
	}
};