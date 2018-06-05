#pragma once
#include <memory>
#include "Parser.h"
#include "SemanticChecker.h"
using SemanticCheckerPtr = std::unique_ptr<SemanticChecker>;
using ParserPtr = std::unique_ptr<Parser>;
class Interpreter
{
public:
	Interpreter() = delete;
	Interpreter(ParserPtr parser, SemanticCheckerPtr sem_check) :
		parser(std::move(parser)),
		semantic_checker(std::move(sem_check)) {};
	~Interpreter() = default;

	void run() const;

private:
	ParserPtr parser;
	SemanticCheckerPtr semantic_checker;
};

