#pragma once
#include <memory>
#include "c:\Users\katar\source\repos\SmartHouseLang\TKOM-proj\statement\Statement.h"
#include "expression\ArithmExpression.h"

using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
using StatementPtr = std::unique_ptr<Statement>;
class CycleStatement :
	public Statement
{
public:
	CycleStatement() = default;
	CycleStatement(StatementPtr proc_call, ArithmExpressionPtr duration) :
		proc_call(std::move(proc_call)),
		duration(std::move(duration))
	{};
	~CycleStatement() = default;
private:
	StatementPtr proc_call;
	ArithmExpressionPtr duration;
};
