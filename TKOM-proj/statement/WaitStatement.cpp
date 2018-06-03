#include "WaitStatement.h"

std::string WaitStatement::toString() const
{
	return "WAIT " + duration->toString();
}

void WaitStatement::run() const
{
	auto period = duration->calculate();
	//sleep for period
}
