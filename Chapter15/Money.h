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
	
	Expression* times(int multiplier);
	Expression* plus(Expression* addend);
	Money* reduce(Bank* bank, std::string to);
};