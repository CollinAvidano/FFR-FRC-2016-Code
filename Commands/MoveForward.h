#ifndef MoveForward_H
#define MoveForward_H

#include "../CommandBase.h"
#include "WPILib.h"

class MoveForward: public CommandBase
{
public:
	MoveForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
