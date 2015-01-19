#ifndef DrivewithJoystick_H
#define DrivewithJoystick_H

#include "../CommandBase.h"
#include "WPILib.h"


class DrivewithJoystick: public CommandBase
{
public:
	DrivewithJoystick();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
