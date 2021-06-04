#pragma once

#include <string>

class Dollar;
class Franc;

class Money
{
protected:
	int amount;
	std::string classType; // Added since C++ does not have a getClass() equivalent

public:
	bool operator==(const Money& other) const 
	{ 
		return amount == other.amount &&
			   classType == other.classType; 
	};

	virtual Money& operator*(const int multiplier) const = 0;
};