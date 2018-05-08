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

BoolExpressionPtr Parser::parseBoolExpression(BoolExpressionPtr leftEval)
{
	TokenType exp_operator = requireToken(log_operators).getType();
	auto rightEval = parseSubLogExpression();
	return std::make_unique<LogicalExpression>(std::move(leftEval), std::move(rightEval), exp_operator);
}

ArithmExpressionPtr Parser::parseSubMultExpression()
{
	Token simp_value = requireToken({ TokenType::IntVal });
	return std::make_unique<IntConstant>(simp_value.getValue());

}

BoolExpressionPtr Parser::parseBoolExpression()
{
	auto leftEval = parseSubLogExpression();
	if (isAcceptableTokenType(log_operators))
		leftEval = parseBoolExpression(std::move(leftEval));
	return leftEval;
}

BoolExpressionPtr Parser::parseSubLogExpression()
{
	BoolExpressionPtr leftEval;
	if (isAcceptableTokenType({ TokenType::BoolTrue, TokenType::BoolFalse }))
		leftEval = parseBoolValue();
	else
		leftEval = parseSubRelExpression();
	return leftEval;
}


BoolExpressionPtr Parser::parseSubRelExpression()
{
	ArithmExpressionPtr leftValue = parseArithmExpression();
	TokenType ex_operator = requireToken(rel_operators).getType();
	ArithmExpressionPtr rightValue = parseArithmExpression();
	return std::make_unique<RelExpression>(std::move(leftValue), std::move(rightValue), ex_operator);
}

BoolExpressionPtr Parser::parseBoolValue()
{
	Token simp_value = requireToken({ TokenType::BoolFalse, TokenType::BoolTrue });
	if (simp_value.getType() == TokenType::BoolTrue)
		std::make_unique<BoolValue>(true);
	return std::make_unique<BoolValue>(false);
}

StatementPtr Parser::parseBlockStatement()
{
	requireToken({ TokenType::LCBracket });
	auto block_statement = std::make_unique<BlockStatement>();
	while (!isAcceptableTokenType({ TokenType::RCBracket }))
	{
		//TODO uncomment after parseStatement() impl
		//auto statement = parseStatement();
		//block_statement->add_instructions(std::move(statement));
	}
	requireToken({ TokenType::RCBracket });
	return block_statement;
}

//TODO implement main logic of basic statements parsing
//StatementPtr Parser::parseStatement()
//{
	
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

StatementPtr Parser::parseGroupStatement()
{
	requireToken({ TokenType::Group });
	auto gr_name = requireToken({ TokenType::Id }).getValue();
	requireToken({ TokenType::Of });
	auto type = requireToken({ TokenType::Id }).getValue();
	return std::make_unique<GroupStatement>(type, gr_name);
}

StatementPtr Parser::parseWaitStatement()
{
	requireToken({ TokenType::Wait });
	auto duration = parseArithmExpression();
	return std::make_unique<WaitStatement>(std::move(duration));
}

StatementPtr Parser::parseDevStatement()
{
	std::string dev_name = requireToken({ TokenType::Id }).getValue();
	std::string atr_name = requireToken({ TokenType::Id }).getValue();
	auto dev_statement = std::make_unique<DevStatement>(dev_name, atr_name);
	requireToken({ TokenType::LBracket });
	while (!isAcceptableTokenType({ TokenType::RBracket }))
	{
		auto arg = parseArithmExpression();
		if (isAcceptableTokenType({ TokenType::Comma }))
		{
			requireToken({ TokenType::Comma });
		}
		dev_statement->add_arguments(std::move(arg));
	}
	return dev_statement;
}

StatementPtr Parser::parseAtrStatement()
{
	std::string dev_name = requireToken({ TokenType::Id }).getValue();
	std::string atr_name = requireToken({ TokenType::Id }).getValue();
	return std::make_unique<AtrStatement>(dev_name, atr_name);
}

VariablePtr Parser::parseVarDeclaration()
{
	std::string type = requireToken({ TokenType::Id }).getValue();
	std::string identifier = requireToken({ TokenType::Id }).getValue();
	std::string bind_addr = parseDevAddress();
	return std::make_unique<Variable>(type, identifier, bind_addr);
}

std::string Parser::parseDevAddress()
{
	//TODO add ip parsing
	//requireToken({ TokenType::LBracket });
	//requireToken({ TokenType::Quot });
	return "test";
}

ParameterPtr Parser::parseParameter()
{
	std::string type = requireToken({ TokenType::Id }).getValue();
	std::string name = requireToken({ TokenType::Id }).getValue();
	return std::make_unique<Parameter>(type, name);
}
