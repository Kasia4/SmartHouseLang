#pragma once
#include <string>
class Statement
{
public:
	virtual ~Statement() = default;
	virtual void run() const = 0;
	virtual std::string toString() const = 0;
};

