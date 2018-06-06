#include "ScriptBody.h"
#include <sstream>
#include <algorithm>

void ScriptBody::add_variable(VariablePtr variable)
{
	auto name = variable->getName();
	if (variables.count(name))
	{
		std::runtime_error("Variable with provided name is already defined");
	}
	variables[name] = std::move(variable);
	//variables[variable->getName()] = std::move(variable);
}

void ScriptBody::add_procedure(ProcedurePtr procedure)
{
	auto name = procedure->getName();
	if (procedures.count(name))
	{
		std::runtime_error("Procedure with provided name is already defined");
	}
	procedures[name] = std::move(procedure);
	//procedures[procedure->getName()] = std::move(procedure);
}

void ScriptBody::add_statement(StatementPtr statement)
{
	instructions.push_back(std::move(statement));
}

const VariablePtr & ScriptBody::get_variable(std::string & name)
{
	if (variables.count(name))
	{
		std::runtime_error("Symbol was not defined");
	}
	return variables[name];
}

const ProcedurePtr & ScriptBody::get_procedure(std::string & name)
{
	if (procedures.count(name))
	{
		std::runtime_error("Symbol was not defined");
	}
	return procedures[name];
}

std::string ScriptBody::toString() const
{
	std::stringstream output;
	if (!variables.empty())
	{
		output << "Vars: ";
		std::for_each(variables.begin(), variables.end(), [&output](const auto& var) { output << var.second->toString(); });
	}
	if (!procedures.empty())
	{
		output << "\nProcedures: ";
		std::for_each(procedures.begin(), procedures.end(), [&output](const auto& proc) { output << proc.second->toString(); });
	}
	if (!instructions.empty())
	{
		output << "\nInstructions: ";
		std::for_each(instructions.begin(), instructions.end(), [&output](const auto& stat) { output << stat->toString(); });
	}
	
	return output.str();
}

void ScriptBody::run() const
{
	std::for_each(instructions.begin(), instructions.end(), [](const auto& stat) { stat->run(); });
}
