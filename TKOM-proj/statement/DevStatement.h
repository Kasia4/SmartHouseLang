#pragma once
#include <list>
#include <memory>
#include "AtrStatement.h"
using StatementPtr = std::unique_ptr<Statement>;
class DevStatement :
	public AtrStatement
{
public:
	DevStatement() = default;
	DevStatement(std::string& dev_name, std::string& atr_name) : AtrStatement(dev_name, atr_name) {};
	~DevStatement() = default;

	void add_arguments(StatementPtr val);
	std::string toString() const override;
	void run() const override;
private:
	std::list<StatementPtr> arguments;
};

