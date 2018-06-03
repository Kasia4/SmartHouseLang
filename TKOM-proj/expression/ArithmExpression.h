#pragma once
#include "../statement/Statement.h"
#include <string>
class ArithmExpression: public Statement
{
public:
	virtual ~ArithmExpression() = default;
	virtual int calculate() const = 0;
	virtual std::string toString() const = 0;
	void run() const override;
};

