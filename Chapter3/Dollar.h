#pragma once

class Dollar
{
public:
	int amount;

	Dollar(int _amount) { amount = _amount; };
	Dollar times(int multiplier) {	return Dollar(amount * multiplier); };	
	bool equals(Dollar dollar) { return amount == dollar.amount; };
};