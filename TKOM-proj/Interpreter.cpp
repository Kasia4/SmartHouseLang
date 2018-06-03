#include "Interpreter.h"

void Interpreter::run()
{
	auto script = parser->parseScriptBody();
	script->run();
}
