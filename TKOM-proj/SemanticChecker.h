#pragma once

#include <memory>
#include "statement\ScriptBody.h"

class SemanticChecker
{
public:
	SemanticChecker() = default;
	~SemanticChecker() = default;
	void check(std::unique_ptr<ScriptBody>& script) const;
};

