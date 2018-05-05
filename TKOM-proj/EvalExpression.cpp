#include "EvalExpression.h"
#include <unordered_map>
#include <functional>
int EvalExpression::calculate() const
{
	int leftValue = l_operand->calculate();
	int rightValue = r_operand->calculate();
	return calculate(leftValue, rightValue);
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
