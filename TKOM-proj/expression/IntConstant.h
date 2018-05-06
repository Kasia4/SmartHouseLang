#pragma once
#include "ArithmExpression.h"
class IntConstant :
	public ArithmExpression
{
public:
	IntConstant() = default;
	IntConstant(int value) : value(value) {};
	~IntConstant() = default;

	int calculate() const override;
private:
	int value;
};

