#include "GroupStatement.h"
#include <sstream>
#include <algorithm>
void GroupStatement::add_component(std::string& name)
{
	components.push_back(name);
}

std::string GroupStatement::toString() const
{
	std::stringstream output;
	std::for_each(components.begin(), components.end(), [&output](const auto& stat) { output << stat; });
	return output.str();
}
