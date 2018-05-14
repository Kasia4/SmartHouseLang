#include "gtest/gtest.h"
#include "pch.h"
#include "ScannerTest.h"
#include "../TKOM-proj/Scanner.cpp"
#include "../TKOM-proj/Token.cpp"

void ScannerTest::SetUp() {
	test_scanner = std::make_unique<Scanner>(test_input);
}

void ScannerTest::setInput(const std::string & content)
{
	test_input.clear();
	test_input.str(content);
}

TEST_F(ScannerTest, testGetKeywordType)
{
	setInput("PROCEDURE fajna");
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::Proc);
}

TEST_F(ScannerTest, testGetKeywordValue)
{
	setInput("PROCEDURE fajna");
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "PROCEDURE");
}

TEST_F(ScannerTest, testGetIdType)
{
	setInput("PROCEDURE fajna");
	test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::Id);
}
TEST_F(ScannerTest, testGetIdValue)
{
	setInput("PROCEDURE fajna");
	test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "fajna");
}

TEST_F(ScannerTest, testGetIntType)
{
	setInput("piec.ustawTemp(150)");
	for(int i=0; i < 4; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::IntVal);
}

TEST_F(ScannerTest, testGetIntValue)
{
	setInput("piec.ustawTemp(150)");
	for (int i = 0; i < 4; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "150");
}

TEST_F(ScannerTest, testGetOperatorType)
{
	setInput("piec.ustawTemp(150)");
	for (int i = 0; i < 3; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::LBracket);
}

TEST_F(ScannerTest, testGetOperatorValue)
{
	setInput("piec.ustawTemp(150)");
	for (int i = 0; i < 3; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "OpenBracket");
}
