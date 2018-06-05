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
	DeviceCreator();
	~DeviceCreator() = default;
	template<class T>
	std::shared_ptr<Device> createDevice(const std::string& id, const std::string& ipAddress);
	
private:
	template<class T>
	static std::unordered_map<std::string, std::function<std::shared_ptr<T>(const std::string&)> > callbacks = {
			{ "piec", std::bind(&DeviceCreator<Oven>::create, std::ref(*this), std::placeholders::_1) },
			{ "pralka", std::bind(&DeviceCreator<WashingMachine>::create, std::ref(*this), std::placeholders::_1) },
			{ "zarowka", std::bind(&DeviceCreator<Bulb>::create, std::ref(*this), std::placeholders::_1) }
	};
	/*std::shared_ptr<Device> createWMachine(const std::string& ipAddress);
	std::shared_ptr<Device> createOven(const std::string& ipAddress);
	std::shared_ptr<Device> createBulb(const std::string& ipAddress);*/
	template<class T>
	std::shared_ptr<T> create(const std::string& ipAddress);

};

template<class T>
inline std::shared_ptr<T> DeviceCreator::create(const std::string & ipAddress)
{
	std::make_shared<T>(ipAddress);
}
template<class T>
std::shared_ptr<Device> DeviceCreator::createDevice(const std::string & id, const std::string & ipAddress)
{
	auto dev = callbacks.find(id);
	if (dev != callbacks.end())
		return dev->second(ipAddress);
	throw std::runtime_error("Undefined device");

}