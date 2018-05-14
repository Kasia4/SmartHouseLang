#pragma once

#include <memory>
#include <sstream>
#include "../TKOM-proj/SourceReader.h"

class SourceReaderTest : public ::testing::Test
{

protected:
	virtual void SetUp();
	void setInput(const std::string & content);

	std::stringstream test_input;
	std::unique_ptr<SourceReader> sourceReader;

};

