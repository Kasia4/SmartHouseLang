#pragma once

#include <istream>
#include <cctype>

#include "Position.h"

class SourceReader
{
public:
	SourceReader(std::istream&input): input(input) {};
	~SourceReader() = default;
	char getNextChar();
	char peek();
	void ignoreWhiteSpaces();
	bool isEof();
	Position getPosition();
private:
	std::istream& input;
	Position position;
	void updatePosition(char getChar);
};

