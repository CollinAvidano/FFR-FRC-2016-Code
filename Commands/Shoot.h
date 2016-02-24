#pragma once

#include "../CommandBase.h"

class ExampleCommand : public CommandBase {
public:
	ExampleCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};