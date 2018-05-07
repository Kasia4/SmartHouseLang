#include "Variable.h"
#include <sstream>
std::string Variable::toString() const
{
	std::stringstream ss;
	ss << "Type: " << type << "Name: " << identifier;
	return ss.str();
}
