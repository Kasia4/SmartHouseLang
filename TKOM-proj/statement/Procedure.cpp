#include "Procedure.h"
#include <sstream>
std::string Procedure::toString() const
{
	std::stringstream output;
	output <<"PROCEDURE " << proc_name << block_statement->toString();
	return output.str();
}

std::string Procedure::getName() const
{
	return proc_name;
}
