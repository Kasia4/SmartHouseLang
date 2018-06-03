#pragma once
#include <memory>
#include "Parser.h"
class Interpreter
{
public:
	Interpreter() = delete;
	Interpreter(std::unique_ptr<Parser> parser) : parser(std::move(parser)) {};
	~Interpreter() = default;

	void run() const;

private:
	std::unique_ptr<Parser> parser;
};

