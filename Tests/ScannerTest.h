#pragma once

#include "../TKOM-proj/Scanner.h"
#include <fstream>
#include <memory>

class ScannerTest : public ::testing::Test
{
protected:
	virtual void SetUp();
	virtual void TearDown();
	void writeFile(std::string content);

	std::fstream test_input;
	std::unique_ptr<Scanner> test_scanner;

};
