#include "BlockStatement.h"
#include <algorithm>
#include <sstream>
std::string BlockStatement::toString() const
{
	std::stringstream instr;
	std::for_each(instructions.begin(), instructions.end(), [&instr](const auto& stat) { instr << stat->toString(); });
	return instr.str();
}

void BlockStatement::add_instructions(StatementPtr statement)
{
	instructions.push_back(std::move(statement));
}
