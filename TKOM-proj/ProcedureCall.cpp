#include "ProcedureCall.h"

void ProcedureCall::add_arguments(ArithmExpressionPtr val)
{
	arguments.push_back(std::move(val));
}
