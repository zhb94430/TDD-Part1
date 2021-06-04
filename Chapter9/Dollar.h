#pragma once

#include <string>

#include "Money.h"

class Dollar : public Money 
{
public:
	Dollar(int _amount, std::string _currency) : Money(_amount, _currency) {};

	// Did not implement author's interruption
	// Because of circular include
	Money& operator*(const int multiplier) const 
	{ return *(new Dollar(amount * multiplier, "USD")); };	
};