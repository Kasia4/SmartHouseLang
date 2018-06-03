#pragma once
#include <memory>
#include "Statement.h"
#include "..\expression\ArithmExpression.h"

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

	std::string toString() const override;
	void run() const override;
private:
	StatementPtr proc_call;
	ArithmExpressionPtr duration;
};
