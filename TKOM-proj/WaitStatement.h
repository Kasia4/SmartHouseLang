#pragma once
#include <memory>
#include "c:\Users\katar\source\repos\SmartHouseLang\TKOM-proj\statement\Statement.h"
#include "expression/ArithmExpression.h"
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
class WaitStatement :
	public Statement
{
public:
	WaitStatement() = default;
	WaitStatement(ArithmExpressionPtr duration) : duration(std::move(duration)) {};
	~WaitStatement() = default;

	std::string toString() const override;
private:
	ArithmExpressionPtr duration;
};
