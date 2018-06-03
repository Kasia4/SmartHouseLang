#pragma once
#include <string>
#include <list>
#include <memory>
#include "..\expression\ArithmExpression.h"
#include "Statement.h"
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
class ProcedureCall :
	public Statement
{
public:
	ProcedureCall() = default;
	ProcedureCall(std::string& proc_name) : proc_name(proc_name) {};
	~ProcedureCall() = default;

	void add_arguments(ArithmExpressionPtr val);
	std::string toString() const override;
	void run() const override;
private:
	std::string proc_name;
	std::list<ArithmExpressionPtr> arguments;
};

