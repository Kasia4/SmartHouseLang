#include "SymbolTable.h"

void SymbolTable::add_symbol(std::string& name, StatementPtr symbol)
{
	if (symbols.count(name))
	{
		std::runtime_error("Symbol is already defined");
	}
	symbols[name] = std::move(symbol);
}

const StatementPtr& SymbolTable::get_symbol(std::string & name)
{
	if (symbols.count(name))
	{
		std::runtime_error("Symbol was not defined");
	}
	return symbols[name];
}
