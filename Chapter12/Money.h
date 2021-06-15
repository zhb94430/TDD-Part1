#pragma once

#include <string>

#include "Expression.h"

class Money : public Expression
{
protected:
	int amount;
	std::string currency; // Added since C++ does not have a getClass() equivalent

public:
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
	
	virtual Money& operator*(const int multiplier) const 
	{ return *(new Money(amount * multiplier, currency)); };

	virtual Money& operator+(const Money& addend) const
	{ return *(new Money(amount + addend.amount, currency)); };

	Expression& plus(Money& addend)
	{ return *(new Money(amount + addend.amount, currency)); };

	std::string getCurrency()
	{
		return currency;
	}
};