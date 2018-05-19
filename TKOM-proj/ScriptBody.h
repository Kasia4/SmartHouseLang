#pragma once
#include "Procedure.h"
#include "statement/Statement.h"
#include "Variable.h"
#include <memory>
#include <list>
using StatementPtr = std::unique_ptr<Statement>;
using ProcedurePtr = std::unique_ptr<Procedure>;
using VariablePtr = std::unique_ptr <Variable>;
class ScriptBody
{
public:
	ScriptBody() = default;
	~ScriptBody() = default;

	void add_variable(VariablePtr variable);
	void add_procedure(ProcedurePtr procedure);
	void add_statement(StatementPtr statement);
	
	std::string toString() const;
private:
	std::list<VariablePtr> variables;
	std::list<ProcedurePtr> procedures;
	std::list<StatementPtr> instructions;

};

