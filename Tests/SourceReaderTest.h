#pragma once

#include <memory>
#include <fstream>
#include "../TKOM-proj/SourceReader.h"

class SourceReaderTest : public ::testing::Test
{

protected:
	virtual void SetUp();
	virtual void TearDown();
	void writeFile(std::string content);
public:
	std::fstream test_input;
	std::unique_ptr<SourceReader> sourceReader;

};

