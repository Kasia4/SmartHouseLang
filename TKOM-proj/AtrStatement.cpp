#include "AtrStatement.h"

std::string AtrStatement::toString() const
{
	return "ATR " + dev_name + " " + atr_name;
}
