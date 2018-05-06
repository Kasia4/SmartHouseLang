#pragma once
#include <memory>
#include "BoolExpression.h"
#include "../Token.h"
class LogicalExpression :
	public BoolExpression
{
	using BoolExpressionPtr = std::unique_ptr<BoolExpression>;
	using TokenType = Token::TokenType;
public:
	LogicalExpression() = default;
	LogicalExpression(BoolExpressionPtr l_operand, BoolExpressionPtr r_operand, TokenType log_operator) :
		l_operand(std::move(l_operand)),
		r_operand(std::move(r_operand)),
		log_operator(log_operator)
	{};
	~LogicalExpression() = default;

	bool calculate() const override;
private:
	bool calculate(bool leftValue, bool rightValue) const;
	BoolExpressionPtr l_operand;
	BoolExpressionPtr r_operand;
	TokenType log_operator;
};

