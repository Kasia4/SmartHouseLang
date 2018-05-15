#include "Parser.h"
#include <algorithm>
#include <iostream>

void Parser::init()
{
	add_operators = { TokenType::AddOp, TokenType::SubOp };
	mult_operators = { TokenType::MultOp, TokenType::DivOp };
	log_operators = { TokenType::ConjOp, TokenType::DisjOp };
	rel_operators = { TokenType::Greater, TokenType::GreaterOrEq,
					  TokenType::Less, TokenType::LessOrEq,
					  TokenType::Equal, TokenType::NotEqual };
	bool_values = { TokenType::BoolTrue, TokenType::BoolFalse };
}

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
	Token simp_value = requireToken(TokenType::IntVal );
	return std::make_unique<IntConstant>(simp_value.getValue());

}

BoolExpressionPtr Parser::parseBoolExpression()
{
	auto leftEval = parseSubLogExpression();
	if (isAcceptableTokenType(log_operators))
		leftEval = parseBoolExpression(std::move(leftEval));
	return leftEval;
}

BoolExpressionPtr Parser::parseBoolExpression(BoolExpressionPtr leftEval)
{
	TokenType exp_operator = requireToken(log_operators).getType();
	auto rightEval = parseSubLogExpression();
	return std::make_unique<LogicalExpression>(std::move(leftEval), std::move(rightEval), exp_operator);
}

BoolExpressionPtr Parser::parseSubLogExpression()
{
	BoolExpressionPtr leftEval;
	if (isAcceptableTokenType(bool_values))
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
	Token simp_value = requireToken(bool_values);
	if (simp_value.getType() == TokenType::BoolTrue)
		return std::make_unique<BoolValue>(true);
	return std::make_unique<BoolValue>(false);
}

ProcedurePtr Parser::parseProcedure()
{
	requireToken(TokenType::Proc);
	auto name = requireToken(TokenType::Id).getValue();
	auto block_statement = parseBlockStatement();
	return std::make_unique<Procedure>(std::move(block_statement));
}

StatementPtr Parser::parseBlockStatement()
{
	requireToken(TokenType::LCBracket);
	auto block_statement = std::make_unique<BlockStatement>();
	while (!isAcceptableTokenType(TokenType::RCBracket))
	{
		//TODO uncomment after parseStatement() impl
		//auto statement = parseStatement();
		//block_statement->add_instructions(std::move(statement));
	}
	requireToken(TokenType::RCBracket);
	return block_statement;
}

//TODO implement main logic of basic statements parsing
StatementPtr Parser::parseStatement()
{
	StatementPtr statement;
	if (isAcceptableTokenType(TokenType::Group))
	{
		statement = parseGroupStatement();
	}
	//TODO: Add parse CycleStatement
	//else if (isAcceptableTokenType(TokenType::Cycle))
	//{
	//	statement = parseCycleStatement();
	//}
	else if (isAcceptableTokenType(TokenType::Wait))
	{
		statement = parseWaitStatement();
	}
	else if (isAcceptableTokenType(TokenType::Action))
	{
		statement = parseProcedureCall();
	}
	else if (isAcceptableTokenType(TokenType::Ifs))
	{
		statement = parseCondStatement();
	}
	else
		statement = parseDevStatement();
	return statement;
}

StatementPtr Parser::parseCondStatement()
{
	requireToken(TokenType::Ifs);
	auto condition = parseBoolExpression();
	requireToken(TokenType::Thens);
	auto if_instr = parseStatement();
	StatementPtr else_instr;
	if (isAcceptableTokenType(TokenType::Elses))
	{
		requireToken(TokenType::Elses);
		else_instr = parseStatement();
	}
	return std::make_unique<CondStatement>(std::move(condition), std::move(if_instr), std::move(else_instr));
}

StatementPtr Parser::parseCycleStatement()
{
	requireToken(TokenType::Cycle);
	requireToken(TokenType::LBracket);
	auto proc_call = parseProcedureCall();
	requireToken(TokenType::Comma);
	auto time_val = parseArithmExpression();
	requireToken(TokenType::RBracket);
	return std::make_unique<CycleStatement>(std::move(proc_call), std::move(time_val));
}

bool Parser::isAcceptableTokenType(TokenType accept_type) const
{
	return scanner->getCurrToken().getType() == accept_type;
}

bool Parser::isAcceptableTokenType(const std::list<TokenType>& accept_types) const
{
	auto currTokenType = scanner->getCurrToken().getType();
	/*return std::any_of(accept_types.begin(), accept_types.end(), 
					   [&currTokenType](const TokenType& type) {return currTokenType == type; });*/
	for (auto& type : accept_types)
	{
		if (currTokenType == type)
			return true;
	}
	return false;
}

Token Parser::requireToken(const std::list<TokenType>& accept_types)
{
	auto currToken = scanner->getCurrToken();
	if (isAcceptableTokenType(accept_types))
	{
		consumeToken();
		return currToken;
	}
	throw std::runtime_error("Unexpected token");
}

Token Parser::requireToken(const TokenType& accept_type)
{
	auto currToken = scanner->getCurrToken();
	if (isAcceptableTokenType(accept_type))
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
	requireToken(TokenType::Group);
	auto gr_name = requireToken(TokenType::Id).getValue();
	requireToken({ TokenType::Of });
	auto type = requireToken(TokenType::Id).getValue();
	return std::make_unique<GroupStatement>(type, gr_name);
}

StatementPtr Parser::parseWaitStatement()
{
	requireToken(TokenType::Wait);
	auto duration = parseArithmExpression();
	return std::make_unique<WaitStatement>(std::move(duration));
}

StatementPtr Parser::parseDevStatement()
{
	std::string dev_name = requireToken(TokenType::Id).getValue();
	std::string atr_name = requireToken(TokenType::Id).getValue();
	auto dev_statement = std::make_unique<DevStatement>(dev_name, atr_name);
	requireToken(TokenType::LBracket);
	while (!isAcceptableTokenType(TokenType::RBracket))
	{
		auto arg = parseArithmExpression();
		dev_statement->add_arguments(std::move(arg));
		if (isAcceptableTokenType(TokenType::Comma))
		{
			requireToken(TokenType::Comma);
		}
		else
			break;
	}
	requireToken(TokenType::RBracket);
	return dev_statement;
}

StatementPtr Parser::parseAtrStatement()
{
	std::string dev_name = requireToken(TokenType::Id).getValue();
	std::string atr_name = requireToken(TokenType::Id).getValue();
	return std::make_unique<AtrStatement>(dev_name, atr_name);
}

VariablePtr Parser::parseVarDeclaration()
{
	std::string type = requireToken(TokenType::Id).getValue();
	std::string identifier = requireToken(TokenType::Id).getValue();
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

StatementPtr Parser::parseProcedureCall()
{
	requireToken(TokenType::Action);
	std::string proc_name = requireToken(TokenType::Id).getValue();
	requireToken(TokenType::LBracket);
	auto proc_call = std::make_unique<ProcedureCall>(proc_name);
	while (!isAcceptableTokenType(TokenType::RBracket))
	{
		auto arg = parseArithmExpression();
		proc_call->add_arguments(std::move(arg));
		if (isAcceptableTokenType(TokenType::Comma))
		{
			requireToken(TokenType::Comma);
		}
		else
			break;
	}
	requireToken(TokenType::RBracket);
	return proc_call;
}

ParameterPtr Parser::parseParameter()
{
	std::string type = requireToken(TokenType::Id).getValue();
	std::string name = requireToken(TokenType::Id).getValue();
	return std::make_unique<Parameter>(type, name);
}
