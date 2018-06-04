#include "EvalExpression.h"
#include <unordered_map>
#include <functional>
#include <sstream>
int EvalExpression::calculate() const
{
	auto leftValue = l_operand->calculate();
	auto rightValue = r_operand->calculate();
	return calculate(leftValue, rightValue);
}

void EvalExpression::run() const
{
}

std::string EvalExpression::toString() const
{
	//TODO: operator toString()
	std::stringstream output;
	output << l_operand->toString() /*<< ex_operator*/ << r_operand->toString();
	return output.str();
}

int EvalExpression::calculate(int leftValue, int rightValue) const
{
	static const std::unordered_map <TokenType, std::function<int(int,int)> > arithm_operations = {
		{ TokenType::AddOp,  [](int l, int r) { return l + r; } },
		{ TokenType::SubOp,  [](int l, int r) { return l - r; } },
		{ TokenType::MultOp, [](int l, int r) { return l * r; } },
		{ TokenType::DivOp,  [](int l, int r) { return l / r; } }
	};
	auto operation = arithm_operations.find(ex_operator);
	if (operation != arithm_operations.end())
		return operation->second(leftValue, rightValue);
	throw std::runtime_error("Wrong operator");
}
