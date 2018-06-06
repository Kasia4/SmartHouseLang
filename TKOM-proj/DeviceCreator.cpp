#include "DeviceCreator.h"

std::unique_ptr<Device> DeviceCreator::createDevice(const std::string & id, const std::string & ipAddress)
{
	static const std::unordered_map<std::string, std::function<std::unique_ptr<Device>(const std::string&)> > callbacks = {
			{ "piec", std::bind(&DeviceCreator::createOven, std::ref(*this), std::placeholders::_1) },
			{ "pralka", std::bind(&DeviceCreator::createWMachine, std::ref(*this), std::placeholders::_1) },
			{ "zarowka", std::bind(&DeviceCreator::createBulb, std::ref(*this), std::placeholders::_1) }
	};
	auto dev = callbacks.find(id);
	if (dev != callbacks.end())
		return dev->second(ipAddress);
	throw std::runtime_error("Undefined device");
}

std::unique_ptr<Device> DeviceCreator::createWMachine(const std::string & ipAddress)
{
	return std::make_unique<WashingMachine>(ipAddress);
}

std::unique_ptr<Device> DeviceCreator::createOven(const std::string & ipAddress)
{
	return std::make_unique<Oven>(ipAddress);
}

std::unique_ptr<Device> DeviceCreator::createBulb(const std::string & ipAddress)
{
	return std::make_unique<Bulb>(ipAddress);
}
