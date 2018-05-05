#include "SourceReader.h"

char SourceReader::getNextChar()
{
	char nextChar = input.get();
	updatePosition(nextChar);
	return nextChar;
}

char SourceReader::peek()
{
	return input.peek();
}


void SourceReader::ignoreWhiteSpaces()
{
	while (input && std::isspace(input.peek()))
		updatePosition(input.get());
}

bool SourceReader::isEof()
{
	return input.peek() == -1 || input.eof();
}

Position SourceReader::getPosition()
{
	return position;
}

unsigned int SourceReader::getCharNum()
{
	return position.getCharNum();
}

void SourceReader::updatePosition(char getChar)
{
	if (getChar == '\n')
		position.updatePositionRow();
	else
		position.updatePositionColumn();
}
