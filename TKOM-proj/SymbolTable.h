#pragma once
#include <unordered_map>
#include <string>
#include <memory>
#include "Device.h"
#include "statement\Procedure.h"

using DevicePtr = std::unique_ptr<Device>;
using ProcedurePtr = std::unique_ptr<Procedure>;

class SymbolTable
{
public:
	SymbolTable() = default;
	~SymbolTable() = default;

	void add_variable(std::string& name, DevicePtr symbol);
	const DevicePtr& get_variable(std::string& name);
	void add_procedure(std::string& name, ProcedurePtr symbol);
	const ProcedurePtr& get_procedure(std::string& name);

private:
	std::unordered_map<std::string, ProcedurePtr> procedures;
	std::unordered_map<std::string, DevicePtr> variables;
};

