#include "Interpreter.h"

void Interpreter::run() const
{
	auto script = parser->parseScriptBody();
	script->run();
}
