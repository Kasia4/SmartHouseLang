#pragma once
class LogicalExpression
{
public:
	virtual ~LogicalExpression() = default;
	virtual bool calculate() const = 0;
};

