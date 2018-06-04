#pragma once
#include "Device.h"
class WashingMachine: public Device
{
public:
	WashingMachine() = delete;
	WashingMachine(std::string& ipAddress) : Device(ipAddress) {};
	~WashingMachine() = default;
};

