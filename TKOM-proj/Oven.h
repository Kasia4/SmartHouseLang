#pragma once
#include "Device.h"
class Oven : public Device
{
public:
	Oven() = delete;
	Oven(const std::string & ipAddress) : Device(ipAddress) {};
	~Oven() = default;
	float getTemperature() const;
private:
	float temperature;
};

