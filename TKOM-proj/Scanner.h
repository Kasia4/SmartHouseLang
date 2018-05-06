#pragma once

#include "Token.h"
#include "SourceReader.h"

class Scanner
{
public:
	Scanner() = delete;
	Scanner(std::istream& input) : source_reader(input) {};
	~Scanner() = default;

	Token getNextToken();
	Token getCurrToken();
	bool checkOperator();
	bool checkEof();
	bool checkIdentifier();
	bool checkValue();

private:
	bool checkKeyword(std::string word);
	std::string getInt();
	std::string getWord();
	Position position;
	SourceReader source_reader;
	Token token;
};

