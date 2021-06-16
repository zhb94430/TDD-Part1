#pragma once

#include "Expression.h"
#include "Money.h"

class Sum : public Expression
{
public:
	Money augend;
	Money addend;

	Sum(Money _augend, Money _addend)
	{ augend = _augend; addend = _addend; };
};