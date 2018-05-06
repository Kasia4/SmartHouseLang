#pragma once
#include <memory>

#include "ArithmExpression.h"
#include "../Token.h"

class EvalExpression :
	public ArithmExpression
{
	using TokenType = Token::TokenType;
	using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
public:
	EvalExpression() = default;
	EvalExpression(ArithmExpressionPtr l_operand, ArithmExpressionPtr r_operand, TokenType ex_operator) :
		l_operand(std::move(l_operand)),
		r_operand(std::move(r_operand)),
		ex_operator(ex_operator)
	{};
	~EvalExpression() = default;
	int calculate() const override;
private:
	ArithmExpressionPtr l_operand;
	ArithmExpressionPtr r_operand;
	TokenType ex_operator;

	int calculate(int leftValue, int rightValue) const;
};

