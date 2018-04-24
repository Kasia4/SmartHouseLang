#include "SourceReader.h"



SourceReader::~SourceReader()
{
}

char SourceReader::getNextChar()
{
	char nextChar;
	if (position >= buffer.size())
	{
		nextChar = input.get();
		buffer += nextChar;
	}
	else
	{
		nextChar = buffer[position];
	}
	++position;
	return nextChar;
}

char SourceReader::peek()
{
	char nextChar;
	if (position >= buffer.size())
	{
		nextChar = input.peek();
	}
	else {
		nextChar = buffer[position];
	}
	return nextChar;
}

void SourceReader::clear()
{
	position = 0;
}

std::string SourceReader::finishReading()
{
	std::string content = buffer;
	buffer = buffer.substr(position);
	clear();
	ignoreWhiteSpaces();
	return content;

}

void SourceReader::ignoreWhiteSpaces()
{
	if (!buffer.empty())
		return;
	while (input && std::isspace(input.peek()))
		input.get();
}

bool SourceReader::isEof()
{
	return buffer.size() == 0 && input.eof();
}

unsigned int SourceReader::getPosition()
{
	return position;
}
