#pragma once

#include "Money.h"

class Franc : public Money
{
public:
	Franc(int _amount) { amount = _amount; };
	Franc& operator*(const int multiplier) const { return *(new Franc(amount * multiplier)); };	
};