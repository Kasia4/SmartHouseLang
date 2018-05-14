#include "RelExpression.h"
#include <unordered_map>
#include <functional>
#include <sstream>
#include <algorithm>
bool RelExpression::calculate() const
{
	auto leftValue = l_operand->calculate();
	auto rightValue = r_operand->calculate();
	return calculate(leftValue, rightValue);
}

std::string RelExpression::toString() const
{
	//TODO: operator toString()
	std::stringstream output;
	output << l_operand->toString() /*<< rel_operator*/ << r_operand->toString();
	return output.str();
}

bool RelExpression::calculate(int leftValue, int rightValue) const
{
	static const std::unordered_map <TokenType, std::function<bool(int,int)> > rel_operations = {
		{ TokenType::Greater,		[](int l, int r) { return l > r; } },
		{ TokenType::GreaterOrEq,   [](int l, int r) { return l >= r; } },
		{ TokenType::Less,			[](int l, int r) { return l < r; } },
		{ TokenType::LessOrEq,		[](int l, int r) { return l <= r; } },
		{ TokenType::Equal,			[](int l, int r) { return l == r; } },
		{ TokenType::NotEqual,		[](int l, int r) { return l != r; } }
	};
	auto operation = rel_operations.find(rel_operator);
	if (operation != rel_operations.end())
		return operation->second(leftValue, rightValue);
	throw std::runtime_error("Wrong operator");
}
