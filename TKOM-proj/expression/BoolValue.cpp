#include "BoolValue.h"


bool BoolValue::calculate() const
{
	return value;
}

std::string BoolValue::toString() const
{
	return value ? "true" : "false";
}
