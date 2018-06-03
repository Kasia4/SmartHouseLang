#pragma once
#include <string>
#include "Statement.h"
class AtrStatement :
	public Statement
{
public:
	AtrStatement() = default;
	AtrStatement(std::string& dev_name, std::string& atr_name) :
		dev_name(dev_name), atr_name(atr_name) {};
	~AtrStatement() = default;

	void run() const override;
	std::string toString() const override;

protected:
	std::string dev_name;
	std::string atr_name;
};

