#include "Device.h"

std::string Device::getIpAddress() const
{
	return ipAddress;
}

Device::State Device::getState() const
{
	return state;
}

void Device::setState(State state)
{
	this->state = state;
}
