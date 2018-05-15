#include "gtest/gtest.h"
#include "pch.h"
#include "ParserTest.h"
#include "../TKOM-proj/Parser.cpp"
#include "../TKOM-proj/expression/EvalExpression.cpp"
#include "../TKOM-proj/expression/RelExpression.cpp"
#include "../TKOM-proj/expression/LogicalExpression.cpp"
#include "../TKOM-proj/expression/BoolValue.cpp"
#include "../TKOM-proj/expression/IntConstant.cpp"
#include "../TKOM-proj/DevStatement.cpp"
#include "../TKOM-proj/CondStatement.cpp"
#include "../TKOM-proj/CycleStatement.cpp"
#include "../TKOM-proj/statement/BlockStatement.cpp"
#include "../TKOM-proj/WaitStatement.cpp"
#include "../TKOM-proj/GroupStatement.cpp"
#include "../TKOM-proj/AtrStatement.cpp"
#include "../TKOM-proj/ProcedureCall.cpp"

void ParserTest::SetUp() {
	std::unique_ptr<Scanner> scanner = std::make_unique<Scanner>(test_input);
	parser = std::make_unique<Parser>(std::move(scanner));
}


void ParserTest::setInput(const std::string& content)
{
	test_input.clear();
	test_input.str(content);
}

TEST_F(ParserTest, testIsAcceptableTokenType)
{
	setInput("+");
	parser->consumeToken();
	EXPECT_TRUE(parser->isAcceptableTokenType({ TokenType::AddOp, TokenType::SubOp }));
}

TEST_F(ParserTest, testIsAcceptableTokenTypeFalse)
{
	setInput("*");
	parser->consumeToken();
	EXPECT_FALSE(parser->isAcceptableTokenType({ TokenType::AddOp, TokenType::SubOp }));
}

TEST_F(ParserTest, testParseArithmExpression)
{
	setInput("2 + 4 - 2 / 2 + 5");
	parser->consumeToken();
	auto calc = parser->parseArithmExpression()->calculate();
	EXPECT_EQ(calc, 10);
}

TEST_F(ParserTest, testParseSubAddExpression)
{
	setInput("2 * 2 * 2 + 5");
	parser->consumeToken();
	auto calc = parser->parseSubAddExpression()->calculate();
	EXPECT_EQ(calc, 8);
}

TEST_F(ParserTest, testParseSubMultExpression)
{
	setInput("2 + 2 * 2 + 5");
	parser->consumeToken();
	auto calc = parser->parseSubMultExpression()->calculate();
	EXPECT_EQ(calc, 2);
}

TEST_F(ParserTest, testParseBoolExpressionAlter)
{
	setInput("T || F");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionAnd)
{
	setInput("T && F");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_FALSE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionGreater)
{
	setInput("3 > 2");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionGreaterOrEq)
{
	setInput("3 >= 2");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionLess)
{
	setInput("3 < 4");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionLessOrEq)
{
	setInput("3 <= 4");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionEqual)
{
	setInput("3 == 4");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_FALSE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionNotEqual)
{
	setInput("3 != 4");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionCompAlt)
{
	setInput("2 > 3 || 3 >= 4");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_FALSE(parsed);
}

TEST_F(ParserTest, testParseBoolExpressionCompAnd)
{
	setInput("2 < 3 && 3 <= 4");
	parser->consumeToken();
	auto parsed = parser->parseBoolExpression()->calculate();
	EXPECT_TRUE(parsed);
}
