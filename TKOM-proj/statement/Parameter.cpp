#include "Parameter.h"

std::string Parameter::toString() const
{
	return type + " " + identifier;
}

std::string Parameter::getName() const
{
	return identifier;
}
