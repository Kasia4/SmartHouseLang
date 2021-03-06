#include "Scanner.h"

#include <cctype>
#include <unordered_map>


Token Scanner::getNextToken()
{
	position = source_reader.getPosition();
	if (checkEof() || checkOperator() || checkValue() || checkIdentifier())
	{
		source_reader.ignoreWhiteSpaces();
		token.setPosition(position);
		return token;
	}
	throw std::runtime_error("Token undefined");
}

Token Scanner::getCurrToken()
{
	return token;
}

bool Scanner::checkOperator()
{
	if (std::isalnum(source_reader.peek()))
		return false;
	
	char currChar = source_reader.getNextChar();
	static const std::unordered_map <char, Token::TokenType> operators = {
		{ '.', Token::TokenType::Dot },
		{ ',', Token::TokenType::Comma },
		{ ';', Token::TokenType::Semicolon },
		{ '(', Token::TokenType::LBracket },
		{ ')', Token::TokenType::RBracket },
		{ '{', Token::TokenType::LCBracket },
		{ '}', Token::TokenType::RCBracket },
		{ '"', Token::TokenType::Quot},
		{ '*', Token::TokenType::MultOp },
		{ '/', Token::TokenType::DivOp },
		{ '+', Token::TokenType::AddOp },
		{ '-', Token::TokenType::SubOp }
	};
	
	auto op = operators.find(currChar);
	if (op != operators.end())
	{
		token = Token(op->second);
		return true;
	}

	if (currChar == '>')
	{
		if (source_reader.peek() == '=')
		{
			token = Token(Token::TokenType::GreaterOrEq);
			source_reader.getNextChar();
		}
		else
			token = Token(Token::TokenType::Greater);
		return true;
	}
	if (currChar == '<')
	{
		if (source_reader.peek() == '=')
		{
			token = Token(Token::TokenType::LessOrEq);
			source_reader.getNextChar();
		}
		else
			token = Token(Token::TokenType::Less);
		return true;
	}
	if (currChar == '=')
	{
		char nextC = source_reader.peek();
		if (nextC == '=')
		{
			token = Token(Token::TokenType::Equal);
			source_reader.getNextChar();
		}
		else if (nextC == '>')
		{
			token = Token(Token::TokenType::LambdaOp);
			source_reader.getNextChar();
		}
		else
			token = Token(Token::TokenType::AssignOp);
		return true;
	}
	if (currChar == '!')
	{
		if (source_reader.peek() == '=')
		{
			token = Token(Token::TokenType::NotEqual);
			source_reader.getNextChar();
			return true;
		}
		else
			return false; //blad
	}
	if (currChar == '&')
	{
		if (source_reader.peek() == '&')
		{
			token = Token(Token::TokenType::ConjOp);
			source_reader.getNextChar();
			return true;
		}
		else
			return false; //blad
	}
	if (currChar == '|')
	{
		if (source_reader.peek() == '|')
		{
			token = Token(Token::TokenType::DisjOp);
			source_reader.getNextChar();
			return true;
		}
		else
			return false; //blad
	}

	return false;
}

bool Scanner::checkEof()
{
	if (source_reader.isEof())
	{
		token = Token(Token::TokenType::Eof);
		return true;
	}
	return false;
}

bool Scanner::checkIdentifier()
{
	std::string word = getWord();
	if (word.empty())
		return false;

	if (!checkKeyword(word))
	{
		token = Token(Token::TokenType::Id);
		token.setValue(word);
	}
	return true;
	
}

bool Scanner::checkValue()
{
	if (!isdigit(source_reader.peek()))
		return false;

	std::string value = getInt();
	token = Token(Token::TokenType::IntVal);
	token.setValue(value);
	return true;
}

bool Scanner::checkKeyword(std::string word)
{
	static const std::unordered_map <std::string, Token::TokenType> keywords = {
		{ "PROCEDURE", Token::TokenType::Proc },
		{ "GROUP", Token::TokenType::Group },
		{ "DO", Token::TokenType::Action },
		{ "IF", Token::TokenType::Ifs },
		{ "THEN", Token::TokenType::Thens },
		{ "ELSE", Token::TokenType::Elses },
		{ "CYCLE", Token::TokenType::Cycle },
		{ "WAIT", Token::TokenType::Wait },
		{ "OF", Token::TokenType::Of },
		{ "T", Token::TokenType::BoolTrue },
		{ "F", Token::TokenType::BoolFalse },
	};
	if (keywords.count(word) == 1)
	{
		token = Token(keywords.at(word));
		return true;
	}
	return false;
}

std::string Scanner::getInt()
{
	std::string value;
	while (isdigit(source_reader.peek()))
	{
		value += source_reader.getNextChar();
	}
	return value;
}

std::string Scanner::getWord()
{
	std::string word;
	if (!isalpha(source_reader.peek()))
		return word;
	do
	{
		word += source_reader.getNextChar();
	} while (isalnum(source_reader.peek()));

	return word;
}
