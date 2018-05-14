#pragma once
#include "Parameter.h"
class Variable :
	public Parameter
{
public:
	Variable() = default;
	Variable(std::string& type, std::string& identifier, std::string& bind_addr) : Parameter(type, identifier)
	{
		bind_addr = bind_addr;
	};
	~Variable() = default;
private:
	std::string bind_addr;
};

