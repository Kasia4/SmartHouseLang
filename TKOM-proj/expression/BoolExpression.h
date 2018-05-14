#pragma once
#include <string>
class BoolExpression
{
public:
	virtual ~BoolExpression() = default;
	virtual bool calculate() const = 0;
	virtual std::string toString() const = 0;
};

