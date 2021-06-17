#pragma once

#include <string>

#include "Expression.h"

class Money : public Expression
{
public:
	int amount;
	std::string currency; // Added since C++ does not have a getClass() equivalent

	Money() {};
	Money(int _amount, std::string _currency);

	bool operator==(const Money& other) const;
	
	Money* times(int multiplier);
	Expression* plus(Money* addend);
	Money* reduce(Bank* bank, std::string to);
};