#pragma once
#include <list>
#include <memory>
#include "AtrStatement.h"
#include "expression/ArithmExpression.h"
using ArithmExpressionPtr = std::unique_ptr<ArithmExpression>;
class DevStatement :
	public AtrStatement
{
public:
	DevStatement() = default;
	DevStatement(std::string& dev_name, std::string& atr_name) : AtrStatement(dev_name, atr_name) {};
	~DevStatement() = default;

	void add_arguments(ArithmExpressionPtr val);
	std::string toString() const override;
private:
	std::list<ArithmExpressionPtr> arguments;
};

