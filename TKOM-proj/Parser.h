#pragma once
#include <memory>
#include <iostream>
#include <initializer_list>
#include "Scanner.h"
#include "expression/EvalExpression.h"
#include "expression/IntConstant.h"
#include "expression/RelExpression.h"
#include "expression/LogicalExpression.h"
#include "expression/BoolValue.h"
#include "Variable.h"
#include "DevStatement.h"
#include "GroupStatement.h"
#include "statement/BlockStatement.h"
#include "Procedure.h"
#include "ProcedureCall.h"
#include "CondStatement.h"
#include "CycleStatement.h"
#include "WaitStatement.h"
using ScannerPtr = std::unique_ptr<Scanner>;
using VariablePtr = std::unique_ptr <Variable>;
using ParameterPtr = std::unique_ptr <Parameter>;
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
using BoolExpressionPtr = std::unique_ptr<BoolExpression>;
using StatementPtr = std::unique_ptr<Statement>;
using ProcedurePtr = std::unique_ptr<Procedure>;
using ProcedureCallPtr = std::unique_ptr<ProcedureCall>;
using TokenType = Token::TokenType;
class Parser
{
public:
	Parser() = delete;
	Parser(ScannerPtr scanner) : scanner(std::move(scanner))
	{
		init();
	};
	void init();
	~Parser() = default;
	//TODO (after whole expr impl) consider templates or traits
	ArithmExpressionPtr parseArithmExpression();
	ArithmExpressionPtr parseSubAddExpression();
	ArithmExpressionPtr parseSubMultExpression();

	BoolExpressionPtr parseBoolExpression();
	BoolExpressionPtr parseSubLogExpression();
	BoolExpressionPtr parseSubRelExpression();
	BoolExpressionPtr parseBoolValue();

	ProcedurePtr parseProcedure();
	StatementPtr parseBlockStatement();
	StatementPtr parseStatement();
	StatementPtr parseCondStatement();
	StatementPtr parseCycleStatement();
	StatementPtr parseGroupStatement();
	StatementPtr parseWaitStatement();
	StatementPtr parseDevStatement();
	StatementPtr parseAtrStatement();
	//TODO SymbolsTable creation
	VariablePtr parseVarDeclaration();
	std::string parseDevAddress();
	StatementPtr parseProcedureCall();
	ParameterPtr parseParameter();

	bool isAcceptableTokenType(const std::list<TokenType>& accept_types) const;
	bool isAcceptableTokenType(TokenType accept_type) const;
	Token requireToken(const std::list<TokenType>& accept_types);
	Token requireToken(const TokenType& accept_type);
	void consumeToken();
private:
	ArithmExpressionPtr parseArithmExpression(ArithmExpressionPtr leftEval);
	ArithmExpressionPtr parseSubAddExpression(ArithmExpressionPtr leftEval);

	//TODO (after statements impl) Add equality and non-equality check
	BoolExpressionPtr parseBoolExpression(BoolExpressionPtr leftEval);

	ScannerPtr scanner;
	std::list<TokenType> add_operators;
	std::list<TokenType> mult_operators;
	std::list<TokenType> log_operators;
	std::list<TokenType> rel_operators;
	std::list<TokenType> bool_values;
		
};

