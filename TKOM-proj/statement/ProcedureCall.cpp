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
	output << "DO " << proc_name << "(";
	std::for_each(arguments.begin(), arguments.end(), [&output](const auto& stat) { output << stat->toString() << " "; });
	output << ")";
	return output.str();
}

void ProcedureCall::run() const
{
}
