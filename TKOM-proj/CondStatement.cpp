#include "CondStatement.h"
#include <sstream>
std::string CondStatement::toString() const
{
	std::stringstream output;
	output << condition->toString() << if_instr->toString() << else_instr->toString();
	return output.str();
}
