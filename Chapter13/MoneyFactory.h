#pragma once

#include "Money.h"

class MoneyFactory
{
public:
	MoneyFactory(){};

	static Money* dollar(int amount);
	static Money* franc(int amount);
};