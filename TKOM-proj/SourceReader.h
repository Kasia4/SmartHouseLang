#pragma once

#include <istream>
#include <cctype>

class SourceReader
{
public:
	SourceReader(std::istream&input): input(input), position(0) {};
	~SourceReader();
	char getNextChar();
	char peek();
	void clear();
	std::string finishReading();
	void ignoreWhiteSpaces();
	bool isEof();
	unsigned int getPosition();

private:
	std::istream& input;
	unsigned int position;
	std::string buffer;
};

