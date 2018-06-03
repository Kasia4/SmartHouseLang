#pragma once
#include "Statement.h"
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
	void run() const override;
private:
	std::string gr_name;
	std::string action;
};

