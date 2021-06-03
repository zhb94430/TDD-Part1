#pragma once

#include "Money.h"

class Dollar : public Money 
{
public:
	Dollar(int _amount) { amount = _amount; };
	Dollar& operator*(const int multiplier) const { return *(new Dollar(amount * multiplier)); };	
};