#include "ScriptBody.h"
#include <sstream>
#include <algorithm>

void ScriptBody::add_variable(VariablePtr variable)
{
	variables.push_back(std::move(variable));
}

void ScriptBody::add_procedure(ProcedurePtr procedure)
{
	procedures.push_back(std::move(procedure));
}

void ScriptBody::add_statement(StatementPtr statement)
{
	instructions.push_back(std::move(statement));
}

std::string ScriptBody::toString() const
{
	std::stringstream output;
	if (!variables.empty())
	{
		output << "Vars: ";
		std::for_each(variables.begin(), variables.end(), [&output](const auto& var) { output << var->toString(); });
	}
	if (!procedures.empty())
	{
		output << "\nProcedures: ";
		std::for_each(procedures.begin(), procedures.end(), [&output](const auto& proc) { output << proc->toString(); });
	}
	if (!instructions.empty())
	{
		output << "\nInstructions: ";
		std::for_each(instructions.begin(), instructions.end(), [&output](const auto& stat) { output << stat->toString(); });
	}
	
	return output.str();
}
