#pragma once

#include <string>

#include "Money.h"


class Franc : public Money
{
public:
	Franc(int _amount, std::string _currency) : Money(_amount, _currency) {};
};