#pragma once

class Money;

class Expression
{
public:
	virtual ~Expression(){};

	virtual Money* reduce(std::string to) = 0;
};