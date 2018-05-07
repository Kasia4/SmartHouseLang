#pragma once
#include <memory>
#include <initializer_list>
#include "Scanner.h"
#include "expression/ArithmExpression.h"
#include "expression/EvalExpression.h"
#include "expression/IntConstant.h"
#include "expression/BoolExpression.h"
#include "expression/RelExpression.h"
#include "expression/LogicalExpression.h"
#include "expression/BoolValue.h"
#include "Variable.h"
using ScannerPtr = std::unique_ptr<Scanner>;
using VariablePtr = std::unique_ptr <Variable> ;
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
using BoolExpressionPtr = std::unique_ptr<BoolExpression>;
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
						  TokenType::Equal, TokenType::NotEqual };
	};
	~Parser() = default;
	//TODO (after whole expr impl) consider templates or traits
	ArithmExpressionPtr parseArithmExpression();
	ArithmExpressionPtr parseSubAddExpression();
	ArithmExpressionPtr parseSubMultExpression();

	BoolExpressionPtr parseBoolExpression();
	BoolExpressionPtr parseSubLogExpression();
	BoolExpressionPtr parseSubRelExpression();
	BoolExpressionPtr parseBoolValue();

	void parseProcedure();
	void parseBlockStatement();
	void parseCondStatement();
	void parseCycleStatement();
	void parseGroupStatement();
	void parseWaitStatement();
	void parseDevStatement();
	void parseAtrStatement();
	//TODO SymbolsTable creation
	VariablePtr parseVarDeclaration();
	std::string parseDevAddress();
	void parseProcedureCall();
	void parseParameters();

	bool isAcceptableTokenType(const std::initializer_list<TokenType>& accept_types) const;
	Token requireToken(const std::initializer_list<TokenType>& accept_types);
	void consumeToken();
private:
	ArithmExpressionPtr parseArithmExpression(ArithmExpressionPtr leftEval);
	ArithmExpressionPtr parseSubAddExpression(ArithmExpressionPtr leftEval);

	//TODO (after statements impl) Add equality and non-equality check
	BoolExpressionPtr parseBoolExpression(BoolExpressionPtr leftEval);

	ScannerPtr scanner;
	std::initializer_list<TokenType> add_operators;
	std::initializer_list<TokenType> mult_operators;
	std::initializer_list<TokenType> log_operators;
	std::initializer_list<TokenType> rel_operators;
		
};

