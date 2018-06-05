#pragma once
#include <string>
class Device
{
public:
	enum class State {
		ON,
		OFF,
	};
	Device() = delete;
	Device(std::string& ipAddress) : ipAddress(ipAddress), state(State::OFF) {};
	virtual ~Device() = default;

	std::string getIpAddress() const;
	State getState() const;
	void setState(State state);
protected:
	State state;
private:
	std::string ipAddress;
};

