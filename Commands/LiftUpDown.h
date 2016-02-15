#ifndef LiftUpDown_H
#define LiftUpDown_H

#include "../CommandBase.h"
#include "WPILib.h"
#include "../RobotMap.h"

class LiftUpDown: public CommandBase
{
public:
	LiftUpDown();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
