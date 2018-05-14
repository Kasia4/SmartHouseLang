#include "DevStatement.h"
#include <sstream>
#include <algorithm>
void DevStatement::add_arguments(ArithmExpressionPtr val)
{
	arguments.push_back(std::move(val));
}

std::string DevStatement::toString() const
{
	std::stringstream output;
	std::for_each(arguments.begin(), arguments.end(), [&output](const auto& stat) { output << stat->toString(); });
	return output.str();
}
