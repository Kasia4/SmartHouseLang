#include "CycleStatement.h"
#include <sstream>
std::string CycleStatement::toString() const
{
	std::stringstream output;
	output << proc_call->toString() << duration->toString();
	return output.str();
}

void CycleStatement::run() const
{
}
