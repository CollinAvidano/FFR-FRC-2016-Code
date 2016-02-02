#ifndef GraspOpenClose_H
#define GraspOpenClose_H

#include "../CommandBase.h"
#include "WPILib.h"

class GraspOpenClose: public CommandBase
{
public:
	GraspOpenClose();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
