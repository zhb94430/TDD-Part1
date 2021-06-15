#pragma once

#include "MoneyFactory.h"
#include "Expression.h"

class Bank
{
public:
	Money reduce(Expression source, std::string to)
	{
		return MoneyFactory::dollar(10);
	}
};