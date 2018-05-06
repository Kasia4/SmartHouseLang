#include "Parser.h"
#include <algorithm>
//ArithmExpressionPtr Parser::parseArithmExpression()
//{
//	auto leftEval = parseSubExpression();
//	while (isAcceptableTokenType({TokenType::AddOp, TokenType::SubOp}))
//		leftEval = parseArithmExpression(std::move(leftEval));
//	return leftEval;
//}
//
//ArithmExpressionPtr Parser::parseArithmExpression(ArithmExpressionPtr leftEval)
//{
//	TokenType exp_operator = requireToken()
//}
//
//ArithmExpressionPtr Parser::parseSubExpression()
//{
//	
//}

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
