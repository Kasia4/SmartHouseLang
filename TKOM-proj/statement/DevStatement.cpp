#include "DevStatement.h"
#include <sstream>
#include <algorithm>
void DevStatement::add_arguments(StatementPtr val)
{
	arguments.push_back(std::move(val));
}

std::string DevStatement::toString() const
{
	std::stringstream output;
	output << dev_name << "." << atr_name << "\(";
	std::for_each(arguments.begin(), arguments.end(), [&output](const auto& stat) { output << stat->toString(); });
	output << "\)";
	return output.str();
}

void DevStatement::run() const
{
}
