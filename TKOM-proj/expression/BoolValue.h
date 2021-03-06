#pragma once
#include "BoolExpression.h"
class BoolValue :
	public BoolExpression
{
public:
	BoolValue() = default;
	BoolValue(bool value) : value(value) {};
	~BoolValue() = default;

	bool calculate() const override;
	std::string toString() const override;
private:
	bool value;
};

