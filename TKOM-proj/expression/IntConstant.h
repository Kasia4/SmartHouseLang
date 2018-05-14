#pragma once
#include <string>
#include "ArithmExpression.h"
class IntConstant :
	public ArithmExpression
{
public:
	IntConstant() = default;
	IntConstant(std::string value_str) { value = toInt(value_str); };
	~IntConstant() = default;

	int calculate() const override;
	int toInt(std::string value);
	std::string toString() const override;
private:
	int value;
};

