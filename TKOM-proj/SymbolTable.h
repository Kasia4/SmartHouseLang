#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "statement\Variable.h"
#include "statement\Procedure.h"

using VariablePtr = std::unique_ptr<Variable>;
using ProcedurePtr = std::unique_ptr<Procedure>;

class SymbolTable
{
public:
	SymbolTable() = default;
	~SymbolTable() = default;

	void add_variable(std::string& name, VariablePtr symbol);
	const VariablePtr& get_variable(std::string& name);
	void add_procedure(std::string& name, ProcedurePtr symbol);
	const ProcedurePtr& get_procedure(std::string& name);

private:
	std::unordered_map<std::string, ProcedurePtr> procedures;
	std::unordered_map<std::string, VariablePtr> variables;
};

