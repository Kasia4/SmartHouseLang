#include "BlockStatement.h"
#include <algorithm>
#include <sstream>
std::string BlockStatement::toString() const
{
	std::stringstream output;
	output << "{";
	std::for_each(instructions.begin(), instructions.end(), [&output](const auto& stat) { output << stat->toString() << " "; });
	output << "}";
	return output.str();
}

void BlockStatement::run() const
{
}

void BlockStatement::add_instructions(StatementPtr statement)
{
	instructions.push_back(std::move(statement));
}
