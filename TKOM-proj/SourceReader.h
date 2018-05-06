#pragma once

#include <istream>
#include <cctype>

#include "Position.h"

class SourceReader
{
public:
	SourceReader() = delete;
	SourceReader(std::istream&input): input(input) {};
	~SourceReader() = default;
	char getNextChar();
	char peek();
	void ignoreWhiteSpaces();
	bool isEof();
	Position getPosition();
	unsigned int getCharNum();
private:
	std::istream& input;
	Position position;
	void updatePosition(char getChar);
};

