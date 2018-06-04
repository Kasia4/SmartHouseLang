#pragma once
#include "Device.h"
class Oven : public Device
{
public:
	Oven() = delete;
	Oven(std::string& ipAddress) : Device(ipAddress) {};
	~Oven() = default;
};

