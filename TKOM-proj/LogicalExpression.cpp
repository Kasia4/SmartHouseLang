#include "LogicalExpression.h"

bool LogicalExpression::calculate() const
{
	auto leftValue = l_operand->calculate();
	auto rightValue = r_operand->calculate();
	return calculate(leftValue, rightValue);
}

bool LogicalExpression::calculate(bool leftValue, bool rightValue) const
{
	switch (log_operator)
	{
	case TokenType::ConjOp:
		return leftValue && rightValue;
	case TokenType::DisjOp:
		return leftValue || rightValue;
	default:
		throw std::runtime_error("Wrong operator");
	}
	
}
