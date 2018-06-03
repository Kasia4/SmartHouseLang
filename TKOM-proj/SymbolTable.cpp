#include "SymbolTable.h"

void SymbolTable::add_variable(std::string& name, VariablePtr symbol)
{
	if (variables.count(name))
	{
		std::runtime_error("Symbol is already defined");
	}
	variables[name] = std::move(symbol);
}

const VariablePtr& SymbolTable::get_variable(std::string & name)
{
	if (variables.count(name))
	{
		std::runtime_error("Symbol was not defined");
	}
	return variables[name];
}

void SymbolTable::add_procedure(std::string & name, ProcedurePtr symbol)
{
	if (procedures.count(name))
	{
		std::runtime_error("Symbol is already defined");
	}
	procedures[name] = std::move(symbol);
}

const ProcedurePtr & SymbolTable::get_procedure(std::string & name)
{
	if (procedures.count(name))
	{
		std::runtime_error("Symbol was not defined");
	}
	return procedures[name];
}
