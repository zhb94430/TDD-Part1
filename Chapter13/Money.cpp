#include "Money.h"
#include "Sum.h"

Expression& Money::plus(Money addend)
{
	return *(new Sum(*this, addend));
}
