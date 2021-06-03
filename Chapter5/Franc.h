#pragma once

class Franc
{
public:
	int amount;

	Franc(int _amount) { amount = _amount; };
	Franc& operator*(const int multiplier) const { return *(new Franc(amount * multiplier)); };	
	bool operator==(const Franc& other) const { return amount == other.amount; };
};