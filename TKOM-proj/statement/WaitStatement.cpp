#include "WaitStatement.h"

std::string WaitStatement::toString() const
{
	return "WAIT " + duration->toString();
}
