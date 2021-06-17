#pragma once

class Money;
class Bank;

class Expression
{
public:
	virtual ~Expression(){};

	virtual Money* reduce(Bank* bank, std::string to) = 0;
};