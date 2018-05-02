#include "gtest/gtest.h"
#include "pch.h"
#include "SourceReaderTest.h"
#include "../TKOM-proj/SourceReader.cpp"

// TODO Change all tests with position after improvements in SourceReader class
void SourceReaderTest::SetUp() {
	test_input.open("unit_tests", std::ios::in | std::ios::out | std::ios::trunc);
	sourceReader = std::make_unique<SourceReader>(test_input);
}
void SourceReaderTest::TearDown() {
	test_input.close();
}
void SourceReaderTest::writeFile(std::string content)
{
	test_input << content;
	if (test_input.fail())
	{
		test_input.clear();
	}
	test_input.seekg(0, std::ios::beg);
}

TEST_F(SourceReaderTest, testGetNextCharOnce)
{
	writeFile("test");
	auto getC = sourceReader->getNextChar();
	EXPECT_EQ(getC, 't');
}

TEST_F(SourceReaderTest, testGetNextCharMult)
{
	writeFile("test");
	for (int i = 0; i < 2; ++i)
	{
		sourceReader->getNextChar();
	}
	auto getC = sourceReader->getNextChar();
	EXPECT_EQ(getC, 's');
}

TEST_F(SourceReaderTest, testPosAfterGetOnce)
{
	writeFile("test");
	sourceReader->getNextChar();
	auto pos = sourceReader->getPosition();
	EXPECT_EQ(pos, 1);
}

TEST_F(SourceReaderTest, testPosAfterGetMult)
{
	writeFile("testtest");
	for (int i = 0; i < 5; ++i)
	{
		sourceReader->getNextChar();
	}
	auto pos = sourceReader->getPosition();
	EXPECT_EQ(pos, 5);
}

TEST_F(SourceReaderTest, testPeek)
{
	writeFile("test");
	sourceReader->peek();
	auto getC = sourceReader->peek();
	EXPECT_EQ(getC, 't');
}

TEST_F(SourceReaderTest, testPosAfterPeekOnce)
{
	writeFile("test");
	sourceReader->peek();
	auto pos = sourceReader->getPosition();
	EXPECT_EQ(pos, 0);
}

TEST_F(SourceReaderTest, testPosAfterPeekMult)
{
	writeFile("test");
	for (int i = 0; i < 5; ++i)
	{
		sourceReader->peek();
	}
	auto pos = sourceReader->getPosition();
	EXPECT_EQ(pos, 0);
}

TEST_F(SourceReaderTest, testIgnoreWhiteSpaces)
{
	writeFile(" test best");
	sourceReader->ignoreWhiteSpaces();
	auto getC = sourceReader->peek();
	EXPECT_EQ(getC, 't');
}

TEST_F(SourceReaderTest, testPosAfterIgnoreWhiteSpaces)
{
	writeFile(" test best");
	sourceReader->ignoreWhiteSpaces();
	sourceReader->getNextChar();
	auto pos = sourceReader->getPosition();
	EXPECT_EQ(pos, 1);
}


