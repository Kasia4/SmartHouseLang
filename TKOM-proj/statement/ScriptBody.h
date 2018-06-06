#pragma once
#include "Procedure.h"
#include "Statement.h"
#include "Variable.h"
#include <memory>
#include <list>
#include <unordered_map>
using StatementPtr = std::unique_ptr<Statement>;
using ProcedurePtr = std::unique_ptr<Procedure>;
using VariablePtr = std::shared_ptr <Variable>;
class ScriptBody
{
public:
	ScriptBody() = default;
	~ScriptBody() = default;

	void add_variable(VariablePtr variable);
	void add_procedure(ProcedurePtr procedure);
	void add_statement(StatementPtr statement);
	
	std::string toString() const;

	void run() const;
private:
	std::unordered_map<std::string, ProcedurePtr> procedures;
	std::unordered_map<std::string, VariablePtr> variables;
	std::list<StatementPtr> instructions;

};

