#pragma once

#include "Money.h"
#include "Dollar.h"
#include "Franc.h"

class MoneyFactory
{
public:
	MoneyFactory(){};

	static Dollar* dollar(int amount) { return new Dollar(amount); };
	static Franc* franc(int amount) { return new Franc(amount); };
};