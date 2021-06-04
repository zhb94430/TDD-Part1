#include "MoneyFactory.h"

Money* MoneyFactory::dollar(int amount) 
{ return new Dollar(amount, "USD"); }

Money* MoneyFactory::franc(int amount) 
{ return new Franc(amount, "CHF"); }