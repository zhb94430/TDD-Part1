#pragma once

class Money
{
protected:
	int amount;

public:
	bool operator==(const Money& other) const { return amount == other.amount; };
};