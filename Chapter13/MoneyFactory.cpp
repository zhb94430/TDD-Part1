#include "MoneyFactory.h"

Money MoneyFactory::dollar(int amount) 
{ return Money(amount, "USD"); }

Money MoneyFactory::franc(int amount) 
{ return Money(amount, "CHF"); }