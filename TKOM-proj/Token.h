#pragma once

#include <string>
#include "Position.h"

class Token
{
public:

	enum class TokenType {
		Eof,
		Dot,
		Comma,
		Semicolon,
		LBracket,
		RBracket,
		LCBracket,
		RCBracket,
		Group,
		Of,
		Proc,
		Action,
		Wait,
		Cycle,
		Ifs,
		Thens,
		Elses,
		ConjOp,
		DisjOp,
		AddOp,
		SubOp,
		MultOp,
		DivOp,
		AssignOp,
		LambdaOp,
		Greater,
		GreaterOrEq,
		Less,
		LessOrEq,
		Equal,
		NotEqual,
		IntVal,
		BoolTrue,
		BoolFalse,
		Quot,
		Id
	};

	Token() = default;
	Token(const TokenType& type) : type(type) {};
	~Token() = default;

	void setValue(std::string value);
	Token::TokenType getType();
	void setPosition(Position position);
	Position getPosition();
	std::string toString();

private:
	TokenType type;
	std::string value;
	Position position;
};

