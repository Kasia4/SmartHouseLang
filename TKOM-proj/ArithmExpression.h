#pragma once
class ArithmExpression
{
public:
	virtual ~ArithmExpression() = default;
	virtual int calculate() const = 0;
};

