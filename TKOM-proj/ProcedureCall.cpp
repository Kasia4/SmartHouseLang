#include "ProcedureCall.h"
#include <sstream>
#include <algorithm>
void ProcedureCall::add_arguments(ArithmExpressionPtr val)
{
	arguments.push_back(std::move(val));
}

std::string ProcedureCall::toString() const
{
	std::stringstream output;
	std::for_each(arguments.begin(), arguments.end(), [&output](const auto& stat) { output << stat->toString(); });
	return output.str();
}
