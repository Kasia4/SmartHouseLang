#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "statement\Statement.h"
using StatementPtr = std::unique_ptr<Statement>;
class SymbolTable
{
public:
	SymbolTable() = default;
	~SymbolTable() = default;
	void add_symbol(std::string& name, StatementPtr symbol);
	const StatementPtr& get_symbol(std::string& name);
private:
	std::unordered_map<std::string, StatementPtr> symbols;
};

