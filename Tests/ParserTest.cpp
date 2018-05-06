#include "gtest/gtest.h"
#include "pch.h"
#include "ParserTest.h"
#include "../TKOM-proj/Parser.cpp"

void ParserTest::SetUp() {
	test_input.open("unit_tests.txt", std::ios::in | std::ios::out | std::ios::trunc);
	std::unique_ptr<Scanner> scanner = std::make_unique<Scanner>(test_input);
	parser = std::make_unique<Parser>(std::move(scanner));
}
void ParserTest::TearDown() {
	test_input.close();
}

void ParserTest::writeFile(std::string content)
{
	test_input << content;
	if (test_input.fail())
	{
		test_input.clear();
	}
	test_input.seekg(0, std::ios::beg);
}

TEST_F(ParserTest, testIsAcceptableTokenType)
{
	writeFile("+");
	parser->consumeToken();
	EXPECT_TRUE(parser->isAcceptableTokenType({ TokenType::AddOp, TokenType::SubOp }));
}

TEST_F(ParserTest, testIsAcceptableTokenTypeFalse)
{
	writeFile("*");
	parser->consumeToken();
	EXPECT_FALSE(parser->isAcceptableTokenType({ TokenType::AddOp, TokenType::SubOp }));
}
