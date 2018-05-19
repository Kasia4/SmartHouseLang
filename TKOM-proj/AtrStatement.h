#pragma once
#include <string>
#include "c:\Users\katar\source\repos\SmartHouseLang\TKOM-proj\statement\Statement.h"
class AtrStatement :
	public Statement
{
public:
	AtrStatement() = default;
	AtrStatement(std::string& dev_name, std::string& atr_name) :
		dev_name(dev_name), atr_name(atr_name) {};
	~AtrStatement() = default;

	std::string toString() const override;

protected:
	std::string dev_name;
	std::string atr_name;
};

