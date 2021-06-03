#pragma once

#include "Money.h"

class Dollar : public Money 
{
public:
	Dollar() { classType = "Dollar"; };
	Dollar(int _amount) : Dollar() { amount = _amount; };
	Dollar& operator*(const int multiplier) const { return *(new Dollar(amount * multiplier)); };	
};