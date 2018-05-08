#include "DevStatement.h"

void DevStatement::add_arguments(ArithmExpressionPtr val)
{
	arguments.push_back(std::move(val));
}
