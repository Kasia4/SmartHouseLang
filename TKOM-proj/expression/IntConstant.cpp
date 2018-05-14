#include "IntConstant.h"

int IntConstant::calculate() const
{
	return value;
}

int IntConstant::toInt(std::string value_str)
{
	int val = 0;
	for (auto digit : value_str)
	{
		val *= 10;
		val += static_cast<int>(digit) - 48;
	}
	return val;
}

std::string IntConstant::toString() const
{
	return "heh" + value;
}
