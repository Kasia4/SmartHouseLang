#include "BlockStatement.h"

void BlockStatement::add_instructions(StatementPtr statement)
{
	instructions.push_back(std::move(statement));
}
