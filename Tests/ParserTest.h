#pragma once

#include "../TKOM-proj/Parser.h"
#include <memory>
#include <fstream>

class ParserTest : public ::testing::Test
{
protected:
	virtual void SetUp();
	virtual void TearDown();
	void writeFile(std::string content);

	std::fstream test_input;
	std::unique_ptr<Parser> parser;
};

