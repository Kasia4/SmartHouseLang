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

	std::shared_ptr<Device> createDevice(const std::string& id, const std::string& ipAddress);
	
private:
	std::shared_ptr<Device> createWMachine(const std::string& ipAddress);
	std::shared_ptr<Device> createOven(const std::string& ipAddress);
	std::shared_ptr<Device> createBulb(const std::string& ipAddress);
	/*template<class T>
	std::shared_ptr<T> create(const std::string& ipAddress);*/

};

//template<class T>
//inline std::shared_ptr<T> DeviceCreator::create(const std::string & ipAddress)
//{
//	std::make_shared<T>(ipAddress);
//}
//template<class T>
//std::shared_ptr<Device> DeviceCreator::createDevice(const std::string & id, const std::string & ipAddress)
//{
//	auto dev = callbacks.find(id);
//	if (dev != callbacks.end())
//		return dev->second(ipAddress);
//	throw std::runtime_error("Undefined device");
//
//}