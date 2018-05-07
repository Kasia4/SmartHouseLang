#pragma once
#include <string>
class Variable
{
public:
	Variable() = default;
	Variable(std::string type, std::string identifier, std::string bind_addr) :
		type(type), identifier(identifier), bind_addr(bind_addr) {};
	~Variable() = default;
	std::string toString() const;
private:
	std::string type;
	std::string identifier;
	std::string bind_addr;
};

