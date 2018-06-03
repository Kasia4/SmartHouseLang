#include "WaitStatement.h"

std::string WaitStatement::toString() const
{
	return "WAIT " + duration->toString();
}

void WaitStatement::run() const
{
}
