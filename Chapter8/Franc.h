#pragma once

#include "Money.h"

class Franc : public Money
{
public:
	Franc() { classType = "Franc"; };
	Franc(int _amount) { amount = _amount; };
	Money& operator*(const int multiplier) const { return *(new Franc(amount * multiplier)); };	
};