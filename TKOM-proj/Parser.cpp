#include "Parser.h"
#include <algorithm>

ArithmExpressionPtr Parser::parseArithmExpression()
{
	auto leftEval = parseSubAddExpression();
	while (isAcceptableTokenType(add_operators))
		leftEval = parseArithmExpression(std::move(leftEval));
	return leftEval;
}

ArithmExpressionPtr Parser::parseArithmExpression(ArithmExpressionPtr leftEval)
{
	TokenType exp_operator = requireToken(add_operators).getType();
	auto rightEval = parseSubAddExpression();
	return std::make_unique<EvalExpression>(std::move(leftEval), std::move(rightEval), exp_operator);

}

ArithmExpressionPtr Parser::parseSubAddExpression()
{
	auto leftEval = parseSubMultExpression();
	while (isAcceptableTokenType(mult_operators))
		leftEval = parseSubAddExpression(std::move(leftEval));
	return leftEval;
}

ArithmExpressionPtr Parser::parseSubAddExpression(ArithmExpressionPtr leftEval)
{
	TokenType exp_operator = requireToken(mult_operators).getType();
	auto rightEval = parseSubMultExpression();
	return std::make_unique<EvalExpression>(std::move(leftEval), std::move(rightEval), exp_operator);
}

ArithmExpressionPtr Parser::parseSubMultExpression()
{
	Token simp_value = requireToken({ TokenType::IntVal });
	return std::make_unique<IntConstant>(1);

}

bool Parser::isAcceptableTokenType(const std::initializer_list<TokenType>& accept_types) const
{
	auto currTokenType = scanner->getCurrToken().getType();
	return std::any_of(accept_types.begin(), accept_types.end(), 
					   [&currTokenType](TokenType type) {return currTokenType == type; });
}

Token Parser::requireToken(const std::initializer_list<TokenType>& accept_types)
{
	auto currToken = scanner->getCurrToken();
	if (isAcceptableTokenType(accept_types))
	{
		consumeToken();
		return currToken;
	}
	throw std::runtime_error("Unexpected token");
}

void Parser::consumeToken()
{
	scanner->getNextToken();
}


