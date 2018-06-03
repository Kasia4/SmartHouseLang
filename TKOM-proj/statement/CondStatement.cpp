#include "CondStatement.h"
#include <sstream>
std::string CondStatement::toString() const
{
	std::stringstream output;
	output << "IF ";
	output << condition->toString() << " THEN " << if_instr->toString() << " ELSE " << else_instr->toString();
	return output.str();
}

void CondStatement::run() const
{
}
