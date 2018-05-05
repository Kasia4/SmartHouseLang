#pragma once
class BoolExpression
{
public:
	virtual ~BoolExpression() = default;
	virtual bool calculate() const = 0;
};

