#pragma once
#include <memory>
#include "BoolExpression.h"
#include "ArithmExpression.h"
#include "../Token.h"
class RelExpression :
	public BoolExpression
{
	using TokenType = Token::TokenType;
	using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
public:
	RelExpression() = default;
	RelExpression(ArithmExpressionPtr l_operand, ArithmExpressionPtr r_operand, TokenType rel_operator) :
		l_operand(std::move(l_operand)),
		r_operand(std::move(r_operand)),
		rel_operator(rel_operator)
	{};
	~RelExpression() = default;
	bool calculate() const override;
private:
	bool calculate(int leftValue, int rightValue) const;
	ArithmExpressionPtr l_operand;
	ArithmExpressionPtr r_operand;
	TokenType rel_operator;
};

