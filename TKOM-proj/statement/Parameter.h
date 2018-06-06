#pragma once
#include <string>
class Parameter
{
public:
	Parameter() = default;
	Parameter(std::string& type, std::string& identifier) :
		type(type), identifier(identifier) {};
	virtual ~Parameter() = default;
	std::string toString() const;
	std::string getName() const;
protected:
	std::string type;
	std::string identifier;
};

