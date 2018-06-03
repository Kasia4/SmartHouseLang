#pragma once
#include <memory>
#include "Statement.h"
#include "../expression/ArithmExpression.h"
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
class WaitStatement :
	public Statement
{
public:
	WaitStatement() = default;
	WaitStatement(ArithmExpressionPtr duration) : duration(std::move(duration)) {};
	~WaitStatement() = default;

	std::string toString() const override;
	void run() const override;
private:
	ArithmExpressionPtr duration;
};
