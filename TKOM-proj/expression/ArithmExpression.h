#pragma once
#include <string>
class ArithmExpression
{
public:
	virtual ~ArithmExpression() = default;
	virtual int calculate() const = 0;
	virtual std::string toString() const = 0;
};

