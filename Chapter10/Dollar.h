#pragma once

#include <string>

#include "Money.h"

class Dollar : public Money 
{
public:
	Dollar(int _amount, std::string _currency) : Money(_amount, _currency) {};
};