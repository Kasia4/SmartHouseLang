#pragma once
#include <string>
class Parameter
{
public:
	Parameter() = default;
	Parameter(std::string& type, std::string& identifier) :
		type(type), identifier(type) {};
	~Parameter() = default;
	std::string toString() const;
protected:
	std::string type;
	std::string identifier;
};

