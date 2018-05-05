#pragma once
#include "LogicalExpression.h"
class BoolValue :
	public LogicalExpression
{
public:
	BoolValue() = default;
	BoolValue(bool value) : value(value) {};
	~BoolValue() = default;

	bool calculate() const override;
private:
	bool value;
};

