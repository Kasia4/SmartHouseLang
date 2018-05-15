#pragma once

#include "../TKOM-proj/Parser.h"
#include <memory>
#include <sstream>

class ParserTest : public ::testing::Test
{
protected:
	virtual void SetUp();
	void setInput(const std::string& content);

	std::stringstream test_input;
	std::unique_ptr<Parser> parser;
};

