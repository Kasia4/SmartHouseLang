#pragma once
#include "Parameter.h"
#include "../Device.h"
#include <memory>
using DevPtr = std::unique_ptr<Device>;

class Variable :
	public Parameter
{
public:
	Variable() = default;
	Variable(std::string& type, std::string& identifier, std::string& bind_addr, DevPtr dev) : Parameter(type, identifier)
	{
		bind_addr = bind_addr;
		device = std::move(dev);
	};
	~Variable() = default;
private:
	std::string bind_addr;
	DevPtr device;
};

