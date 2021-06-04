#pragma once

#include <string>

#include "Money.h"


class Franc : public Money
{
public:
	Franc(int _amount, std::string _currency) : Money(_amount, _currency) {};

	// Did not implement author's interruption
	// Because of circular include
	Money& operator*(const int multiplier) const 
	{ return *(new Franc(amount * multiplier, "CHF")); };
};