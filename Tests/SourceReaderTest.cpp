#include "gtest/gtest.h"
#include "pch.h"
#include "SourceReaderTest.h"
#include "../TKOM-proj/SourceReader.cpp"
#include "../TKOM-proj/Position.cpp"

void SourceReaderTest::SetUp() {
	sourceReader = std::make_unique<SourceReader>(test_input);
}

void SourceReaderTest::setInput(const std::string & content)
{
	test_input.clear();
	test_input.str(content);
}

TEST_F(SourceReaderTest, testGetNextCharOnce)
{
	setInput("test");
	auto getC = sourceReader->getNextChar();
	EXPECT_EQ(getC, 't');
}

TEST_F(SourceReaderTest, testGetNextCharMult)
{
	setInput("test");
	for (int i = 0; i < 2; ++i)
	{
		sourceReader->getNextChar();
	}
	auto getC = sourceReader->getNextChar();
	EXPECT_EQ(getC, 's');
}

TEST_F(SourceReaderTest, testPosAfterGetOnce)
{
	setInput("test");
	sourceReader->getNextChar();
	auto charNum = sourceReader->getCharNum();
	EXPECT_EQ(charNum, 1);
}

TEST_F(SourceReaderTest, testPosAfterGetMult)
{
	setInput("testtest");
	for (int i = 0; i < 5; ++i)
	{
		sourceReader->getNextChar();
	}
	auto charNum = sourceReader->getCharNum();
	EXPECT_EQ(charNum, 5);
}

TEST_F(SourceReaderTest, testPeek)
{
	setInput("test");
	sourceReader->peek();
	auto getC = sourceReader->peek();
	EXPECT_EQ(getC, 't');
}

TEST_F(SourceReaderTest, testPosAfterPeekOnce)
{
	setInput("test");
	sourceReader->peek();
	auto charNum = sourceReader->getCharNum();
	EXPECT_EQ(charNum, 0);
}

TEST_F(SourceReaderTest, testPosAfterPeekMult)
{
	setInput("test");
	for (int i = 0; i < 5; ++i)
	{
		sourceReader->peek();
	}
	auto charNum = sourceReader->getCharNum();
	EXPECT_EQ(charNum, 0);
}

TEST_F(SourceReaderTest, testIgnoreWhiteSpaces)
{
	setInput(" test best");
	sourceReader->ignoreWhiteSpaces();
	auto getC = sourceReader->peek();
	EXPECT_EQ(getC, 't');
}

TEST_F(SourceReaderTest, testPosAfterIgnoreWhiteSpaces)
{
	setInput(" test best");
	sourceReader->ignoreWhiteSpaces();
	sourceReader->getNextChar();
	auto charNum = sourceReader->getCharNum();
	EXPECT_EQ(charNum, 2);
}

TEST_F(SourceReaderTest, testEof)
{
	setInput("\n");
	sourceReader->getNextChar();
	sourceReader->getNextChar();
	EXPECT_TRUE(sourceReader->isEof());
}

