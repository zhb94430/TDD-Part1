#pragma once

#include "Money.h"
#include "Dollar.h"
#include "Franc.h"

class MoneyFactory
{
public:
	MoneyFactory(){};

	static Money* dollar(int amount);
	static Money* franc(int amount);
};