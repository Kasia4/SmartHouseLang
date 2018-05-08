#pragma once
#include <string>
class Parameter
{
public:
	Parameter() = default;
	Parameter(std::string& type, std::string& identifier) :
		type(type), identifier(type) {};
	~Parameter() = default;
protected:
	std::string type;
	std::string identifier;
};

