#pragma once

#include "Command.h"

class CmdVarBool : public Command
{
public:
	const char* GetName() override
	{
		return "bool";
	}

	const char* GetDescription() override
	{
		return "Declates a bool variable."
			"\n"
			"syntax: bool <name> [= <value>];";
	}

	bool Execute(const std::vector<std::string>& params) override;
};