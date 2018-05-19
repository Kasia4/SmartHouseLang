#pragma once
#include "c:\Users\katar\source\repos\SmartHouseLang\TKOM-proj\statement\Statement.h"
class GroupActionStatement :
	public Statement
{
public:
	GroupActionStatement() = default;
	GroupActionStatement(std::string gr_name, std::string action) :
		gr_name(gr_name),
		action(action)
	{};
	~GroupActionStatement() = default;

	std::string toString() const override;
private:
	std::string gr_name;
	std::string action;
};

