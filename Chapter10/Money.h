#pragma once

#include <string>

class Dollar;
class Franc;

class Money
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

	std::string getCurrency()
	{
		return currency;
	}
};