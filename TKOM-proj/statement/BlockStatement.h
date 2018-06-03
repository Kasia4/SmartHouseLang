#pragma once
#include <list>
#include <memory>
#include "Statement.h"
using StatementPtr = std::unique_ptr<Statement>;
class BlockStatement :
	public Statement
{
public:
	BlockStatement() = default;
	~BlockStatement() = default;

	std::string toString() const override;
	void run() const override;
	void add_instructions(StatementPtr statement);
private:
	std::list<StatementPtr> instructions;
};

