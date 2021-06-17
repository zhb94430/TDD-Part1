#include "Money.h"
#include "Sum.h"

Money::Money(int _amount, std::string _currency)
{
	amount = _amount;
	currency = _currency;
}

bool Money::operator==(const Money& other) const 
{ 
	return amount == other.amount &&
		   currency == other.currency; 
}

Money* Money::times(int multiplier)
{ 
	return new Money(amount * multiplier, currency); 
}

Expression* Money::plus(Money* addend)
{
	return new Sum(this, addend);
}
