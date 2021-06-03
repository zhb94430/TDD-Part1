#pragma once

class Dollar
{
public:
	int amount;

	Dollar(int _amount) {amount = _amount;};
	void times(int multiplier) {amount *= multiplier;};	
};