#pragma once
#include <string>
class Device
{
public:
	Device() = delete;
	Device(std::string& ipAddress) : ipAddress(ipAddress) {};
	~Device() = default;
	std::string getIpAddress() const;
private:
	std::string ipAddress;
};

