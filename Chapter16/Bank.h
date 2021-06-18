#pragma once

#include <map>

#include "MoneyFactory.h"
#include "Expression.h"
#include "Pair.h"

class Bank
{
public:
	std::map<Pair, int> rates;

	Money* reduce(Expression* source, std::string to)
	{
		return source->reduce(this, to);
	}

	void addRate(std::string from, std::string to, int rate)
	{ rates.insert(std::pair<Pair, int>(Pair(from, to), rate)); };

	int rate(std::string from, std::string to)
	{ 
		if (from == to)
			return 1;
		else 
			return rates.find(Pair(from, to))->second; 	
	};
};