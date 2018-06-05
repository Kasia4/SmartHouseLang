#pragma once
#include "Device.h"
class Bulb :
	public Device
{
public:
	Bulb() = delete;
	Bulb(const std::string & ipAddress) : Device(ipAddress) {};
	~Bulb() = default;
	float getLevel() const;
private:
	float level;
};

