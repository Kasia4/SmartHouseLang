#pragma once

#include <string>
class Token
{
public:

	enum class TokenType {
		Eof,
		Dot,
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
		Id,
		Undef
	};
	Token() = default;
	Token(const TokenType& type) : type(type) {};
	~Token();
	void setValue(std::string value);
	Token::TokenType getType();
	void setPosition(unsigned int position);
	unsigned int getPosition();
	std::string toString();
private:
	TokenType type;
	std::string value;
	unsigned int position;
};

