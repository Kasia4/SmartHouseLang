#include "GroupActionStatement.h"
#include <sstream>

std::string GroupActionStatement::toString() const
{
	std::stringstream output;
	output << gr_name << "." << action;
	return output.str();
}

void GroupActionStatement::run() const
{
}
