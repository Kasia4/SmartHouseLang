#pragma once

#include "Token.h"
#include "SourceReader.h"

class Scanner
{
public:
	Scanner() = default;
	Scanner(std::istream& input) : source_reader(input) {};
	~Scanner();

	Token getNextToken();
	bool checkOperator();
	bool checkEof();
	bool checkIdentifier();
	bool checkValue();

private:
	void ignoreWhiteSpaces();
	bool checkKeyword(std::string word);
	std::string clearBuffer();
	std::string getInt();
	std::string getWord();

	unsigned int position;
	SourceReader source_reader;
	Token token;
};

