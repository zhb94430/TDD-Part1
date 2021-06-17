#include "MoneyFactory.h"

Money* MoneyFactory::dollar(int amount) 
{ return new Money(amount, "USD"); }

Money* MoneyFactory::franc(int amount) 
{ return new Money(amount, "CHF"); }