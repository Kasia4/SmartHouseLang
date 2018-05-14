#pragma once
#include <memory>
#include "statement\Statement.h"
using StatementPtr = std::unique_ptr<Statement>;
class Procedure
{
public:
	Procedure() = default;
	//TODO: add name of procedure
	Procedure(StatementPtr block_statement) : block_statement(std::move(block_statement)) {};
	~Procedure() = default;
	std::string toString() const;
private:
	std::string proc_name;
	StatementPtr block_statement;
};

