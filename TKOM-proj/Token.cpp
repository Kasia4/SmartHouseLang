#include <unordered_map>

#include "Token.h"



Token::~Token()
{
}

void Token::setValue(std::string value)
{
	value = value;
}

Token::TokenType Token::getType()
{
	return type;
}

void Token::setPosition(unsigned int position)
{
	position = position;
}

unsigned int Token::getPosition()
{
	return position;
}

std::string Token::toString()
{
	if (type == Token::TokenType::Eof)
		return "End of file";
	if (type == Token::TokenType::IntVal || type == Token::TokenType::Id)
		return value;
	if (type == Token::TokenType::Undef)
		return "Undefined";
	static const std::unordered_map <Token::TokenType, std::string> knownWords = {
		{ Token::TokenType::Proc, "PROCEDURE" },
		{ Token::TokenType::Group, "GROUP" },
		{ Token::TokenType::Action, "DO" },
		{ Token::TokenType::Ifs, "IF" },
		{ Token::TokenType::Thens, "THEN" },
		{ Token::TokenType::Elses,"ELSE" },
		{ Token::TokenType::Cycle, "CYCLE" },
		{ Token::TokenType::Wait, "WAIT" },
		{ Token::TokenType::Of, "OF" },
		{ Token::TokenType::BoolTrue, "T" },
		{ Token::TokenType::BoolFalse, "F" },
		{ Token::TokenType::Dot, "Dot" },
		{ Token::TokenType::Semicolon, "Semicolon" },
		{ Token::TokenType::LBracket, "OpenBracket" },
		{ Token::TokenType::RBracket, "CloseBracket" },
		{ Token::TokenType::LCBracket, "OpenCurlyBracket" },
		{ Token::TokenType::RCBracket, "CloseCurlyBracket" },
		{ Token::TokenType::AddOp, "Plus" },
		{ Token::TokenType::SubOp, "Minus" },
		{ Token::TokenType::MultOp, "Multiply" },
		{ Token::TokenType::DivOp, "Divide" },
		{ Token::TokenType::Greater, "Greater" },
		{ Token::TokenType::GreaterOrEq, "GreaterOrEqual" },
		{ Token::TokenType::Less, "Less" },
		{ Token::TokenType::LessOrEq, "LessOrEqual" },
		{ Token::TokenType::LambdaOp, "LambdaOperator" },
		{ Token::TokenType::AssignOp, "AssignmentOperator" },
		{ Token::TokenType::Equal, "Equal" },
		{ Token::TokenType::NotEqual, "NotEqual" },
		{ Token::TokenType::ConjOp, "Conjunction" },
		{ Token::TokenType::DisjOp, "Disjoint" },
	};
	return knownWords.at(type);
}
