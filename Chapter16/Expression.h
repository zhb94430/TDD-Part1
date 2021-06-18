#pragma once

class Money;
class Bank;

class Expression
{
public:
	virtual ~Expression(){};

	virtual Expression* plus(Expression* addend) = 0;
	virtual Expression* times(int multiplier) = 0;
	virtual Money* reduce(Bank* bank, std::string to) = 0;
};