#include "gtest/gtest.h"
#include "pch.h"
#include "ScannerTest.h"
#include "../TKOM-proj/Scanner.cpp"
#include "../TKOM-proj/Token.cpp"

void ScannerTest::SetUp() {
	test_input.open("unit_tests", std::ios::in | std::ios::out | std::ios::trunc);
	test_scanner = std::make_unique<Scanner>(test_input);
}
void ScannerTest::TearDown() {
	test_input.close();
}

void ScannerTest::writeFile(std::string content)
{
	test_input << content;
	if (test_input.fail())
	{
		test_input.clear();
	}
	test_input.seekg(0, std::ios::beg);
}

TEST_F(ScannerTest, testGetKeywordType)
{
	writeFile("PROCEDURE fajna");
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::Proc);
}

TEST_F(ScannerTest, testGetKeywordValue)
{
	writeFile("PROCEDURE fajna");
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "PROCEDURE");
}

TEST_F(ScannerTest, testGetIdType)
{
	writeFile("PROCEDURE fajna");
	test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::Id);
}
TEST_F(ScannerTest, testGetIdValue)
{
	writeFile("PROCEDURE fajna");
	test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "fajna");
}

TEST_F(ScannerTest, testGetIntType)
{
	writeFile("piec.ustawTemp(150)");
	for(int i=0; i < 4; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::IntVal);
}
TEST_F(ScannerTest, testGetIntValue)
{
	writeFile("piec.ustawTemp(150)");
	for (int i = 0; i < 4; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "150");
}
TEST_F(ScannerTest, testGetOperatorType)
{
	writeFile("piec.ustawTemp(150)");
	for (int i = 0; i < 3; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.getType(), Token::TokenType::LBracket);
}
TEST_F(ScannerTest, testGetOperatorValue)
{
	writeFile("piec.ustawTemp(150)");
	for (int i = 0; i < 3; ++i)
		test_scanner->getNextToken();
	auto token = test_scanner->getNextToken();
	EXPECT_EQ(token.toString(), "OpenBracket");
}
