#pragma once
#include <memory>
#include <initializer_list>
#include "Scanner.h"
#include "expression/ArithmExpression.h"
using ScannerPtr = std::unique_ptr<Scanner>;
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
using TokenType = Token::TokenType;
class Parser
{
public:
	Parser() = delete;
	Parser(ScannerPtr scanner) : scanner(std::move(scanner)) {};
	~Parser() = default;

	ArithmExpressionPtr parseArithmExpression();
	ArithmExpressionPtr parseArithmExpression(ArithmExpressionPtr leftEval);
	ArithmExpressionPtr parseSubExpression();
	bool isAcceptableTokenType(const std::initializer_list<TokenType>& accept_types) const;
	Token requireToken(const std::initializer_list<TokenType>& accept_types);
	void consumeToken();
private:
	ScannerPtr scanner;
};

