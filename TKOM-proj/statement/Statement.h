#pragma once
#include <string>
class Statement
{
public:
	virtual ~Statement() = default;
	//virtual void execute() = 0;
	virtual std::string toString() const = 0;
};

