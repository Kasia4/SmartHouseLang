#pragma once
#include <memory>
#include "c:\Users\katar\source\repos\SmartHouseLang\TKOM-proj\statement\Statement.h"
#include "expression\BoolExpression.h"
using BoolExpressionPtr = std::unique_ptr<BoolExpression>;
using StatementPtr = std::unique_ptr<Statement>;
class CondStatement :
	public Statement
{
public:
	CondStatement() = default;
	CondStatement(BoolExpressionPtr condition, StatementPtr if_instr, StatementPtr else_instr) :
		condition(std::move(condition)),
		if_instr(std::move(if_instr)),
		else_instr(std::move(else_instr))
	{};
	~CondStatement() = default;
private:
	BoolExpressionPtr condition;
	StatementPtr if_instr;
	StatementPtr else_instr;

};

