#pragma once

class Dollar
{
public:
	int amount;

	Dollar(int _amount) { amount = _amount; };
	Dollar& operator*(const int multiplier) const { return *(new Dollar(amount * multiplier)); };	
	bool operator==(const Dollar& other) const { return amount == other.amount; };
};