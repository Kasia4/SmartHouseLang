
#include <iostream>
#include <fstream>
#include "Scanner.h"

int main(int argc, char** argv)
{
	std::string file;
	if (argc < 2)
		file = "test.txt";
	else
		file = argv[1];
	std::ifstream input;
	input.open(file.c_str(), std::ifstream::in);
	if (!input.is_open())
	{
		std::cout << "Error during opening the file";
		return 1;
	}
	Scanner scanner(input);
	Token nextToken;
	do
	{
		nextToken = scanner.getNextToken();
		std::cout << nextToken.toString() << std::endl;
	} while (nextToken.getType() != Token::TokenType::Eof);

	return 0;
}