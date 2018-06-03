#include "AtrStatement.h"

void AtrStatement::run() const
{
}

std::string AtrStatement::toString() const
{
	return "ATR " + dev_name + " " + atr_name;
}
