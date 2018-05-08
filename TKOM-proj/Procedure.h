#pragma once
#include <memory>
#include "statement\Statement.h"
using StatementPtr = std::unique_ptr<Statement>;
class Procedure
{
public:
	Procedure() = default;
	Procedure(StatementPtr block_statement) : block_statement(std::move(block_statement)) {};
	~Procedure() = default;
private:
	StatementPtr block_statement;
};

