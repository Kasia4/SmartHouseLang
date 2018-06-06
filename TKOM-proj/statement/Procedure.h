#pragma once
#include <memory>
#include "Statement.h"
using StatementPtr = std::unique_ptr<Statement>;
class Procedure
{
public:
	Procedure() = default;
	Procedure(std::string proc_name, StatementPtr block_statement) : proc_name(proc_name), block_statement(std::move(block_statement)) {};
	~Procedure() = default;
	std::string toString() const;
	std::string getName() const;
private:
	std::string proc_name;
	StatementPtr block_statement;
};

