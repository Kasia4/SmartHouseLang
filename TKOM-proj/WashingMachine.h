#pragma once
#include "Device.h"
class WashingMachine: public Device
{
public:
	WashingMachine() = delete;
	WashingMachine(const std::string & ipAddress) : Device(ipAddress) {};
	~WashingMachine() = default;
};

