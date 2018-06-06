#pragma once
#include <unordered_map>
#include <functional>
#include <memory>

#include "WashingMachine.h"
#include "Oven.h"
#include "Bulb.h"

class DeviceCreator
{
public:
	DeviceCreator() = default;
	~DeviceCreator() = default;

	std::unique_ptr<Device> createDevice(const std::string& id, const std::string& ipAddress);
	
private:
	std::unique_ptr<Device> createWMachine(const std::string& ipAddress);
	std::unique_ptr<Device> createOven(const std::string& ipAddress);
	std::unique_ptr<Device> createBulb(const std::string& ipAddress);
	/*template<class T>
	std::unique_ptr<T> create(const std::string& ipAddress);*/

};

//template<class T>
//inline std::unique_ptr<T> DeviceCreator::create(const std::string & ipAddress)
//{
//	std::make_unique<T>(ipAddress);
//}
//template<class T>
//std::unique_ptr<Device> DeviceCreator::createDevice(const std::string & id, const std::string & ipAddress)
//{
//	auto dev = callbacks.find(id);
//	if (dev != callbacks.end())
//		return dev->second(ipAddress);
//	throw std::runtime_error("Undefined device");
//
//}