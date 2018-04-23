#include "Scanner.h"

#include <cctype>
#include <unordered_map>


Scanner::~Scanner()
{
}

Token Scanner::getNextToken()
{
	position = source_reader.getPosition();
	if (checkEof() || checkOperator() || checkValue() || checkIdentifier())
	{
		token.setPosition(position);
		return token;
	}
	return Token(Token::TokenType::Undef);
}

bool Scanner::checkOperator()
{
	if (std::isalnum(source_reader.peek()))
		return false;
	char currChar = source_reader.getNextChar();
	if (currChar == '.')
	{
		token = Token(Token::TokenType::Dot);
		source_reader.finishReading();
		return true;
	}
	if (currChar == ';')
	{
		token = Token(Token::TokenType::Semicolon);
		source_reader.finishReading();
		return true;
	}
	if (currChar == '(')
	{
		token = Token(Token::TokenType::LBracket);
		source_reader.finishReading();
		return true;
	}
	if (currChar == ')')
	{
		token = Token(Token::TokenType::RBracket);
		source_reader.finishReading();
		return true;
	}
	if (currChar == '{')
	{
		token = Token(Token::TokenType::LCBracket);
		source_reader.finishReading();
		return true;
	}
	if (currChar == '}')
	{
		token = Token(Token::TokenType::RCBracket);
		source_reader.finishReading();
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
		source_reader.finishReading();
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
		source_reader.finishReading();
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
		source_reader.finishReading();
		return true;
	}
	if (currChar == '!')
	{
		if (source_reader.peek() == '=')
		{
			token = Token(Token::TokenType::NotEqual);
			source_reader.getNextChar();
			source_reader.finishReading();
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
			source_reader.finishReading();
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
			source_reader.finishReading();
			return true;
		}
		else
			return false; //blad
	}
	if (currChar == '*')
	{
		token = Token(Token::TokenType::MultOp);
		source_reader.finishReading();
		return true;
	}
	if (currChar == '/')
	{
		token = Token(Token::TokenType::DivOp);
		source_reader.finishReading();
		return true;
	}
	if (currChar == '+')
	{
		token = Token(Token::TokenType::AddOp);
		source_reader.finishReading();
		return true;
	}
	if (currChar == '-')
	{
		token = Token(Token::TokenType::SubOp);
		source_reader.finishReading();
		return true;
	}

	source_reader.clear();
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
	{
		source_reader.clear();
		return false;
	}
	if (!checkKeyword(word))
	{
		token = Token(Token::TokenType::Id);
		token.setValue(word);
	}
	source_reader.finishReading();
	return true;
	
}

bool Scanner::checkValue()
{
	if (!isdigit(source_reader.peek()))
	{
		source_reader.clear();
		return false;
	}
	std::string value = getInt();
	token = Token(Token::TokenType::IntVal);
	token.setValue(value);
	source_reader.finishReading();
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
	{
		return word;
	}
	do
	{
		word += source_reader.getNextChar();
	} while (isalnum(source_reader.peek()));

	return word;
}
