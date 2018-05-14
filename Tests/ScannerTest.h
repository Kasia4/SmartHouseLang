#pragma once

#include "../TKOM-proj/Scanner.h"
#include <sstream>
#include <memory>

class ScannerTest : public ::testing::Test
{
protected:
	virtual void SetUp();
	void setInput(const std::string & content);

	std::stringstream test_input;
	std::unique_ptr<Scanner> test_scanner;

};
