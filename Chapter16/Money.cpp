#include "Money.h"
#include "Sum.h"
#include "Bank.h"

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

Expression* Money::times(int multiplier)
{ 
	return new Money(amount * multiplier, currency); 
}

Expression* Money::plus(Expression* addend)
{
	return new Sum(this, addend);
}

Money* Money::reduce(Bank* bank, std::string to)
{
	int rate = bank->rate(currency, to);

    return new Money(amount/rate, to);
}