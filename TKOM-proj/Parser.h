#pragma once
#include <memory>
#include <initializer_list>
#include "Scanner.h"
#include "expression/ArithmExpression.h"
#include "expression/EvalExpression.h"
#include "expression/IntConstant.h"
using ScannerPtr = std::unique_ptr<Scanner>;
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
using TokenType = Token::TokenType;
class Parser
{
public:
	Parser() = delete;
	Parser(ScannerPtr scanner) : scanner(std::move(scanner))
	{
		add_operators = { TokenType::AddOp, TokenType::SubOp };
		mult_operators = { TokenType::MultOp, TokenType::DivOp };
		log_operators = { TokenType::ConjOp, TokenType::DisjOp };
		rel_operators = { TokenType::Greater, TokenType::GreaterOrEq,
						  TokenType::Less, TokenType::LessOrEq,
						  TokenType::Equal, TokenType::NotEqual, };
	};
	~Parser() = default;

	ArithmExpressionPtr parseArithmExpression();
	ArithmExpressionPtr parseSubAddExpression();
	ArithmExpressionPtr parseSubMultExpression();
	bool isAcceptableTokenType(const std::initializer_list<TokenType>& accept_types) const;
	Token requireToken(const std::initializer_list<TokenType>& accept_types);
	void consumeToken();
private:
	ArithmExpressionPtr parseArithmExpression(ArithmExpressionPtr leftEval);
	ArithmExpressionPtr parseSubAddExpression(ArithmExpressionPtr leftEval);

	ScannerPtr scanner;
	std::initializer_list<TokenType> add_operators;
	std::initializer_list<TokenType> mult_operators;
	std::initializer_list<TokenType> log_operators;
	std::initializer_list<TokenType> rel_operators;
		
};

