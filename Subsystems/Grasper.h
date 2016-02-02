#ifndef Grasper_H
#define Grasper_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class Grasper: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	SpeedController *screw;
public:
	Grasper();
	void InitDefaultCommand();
	void Open();
	void Close();
	void Stop();
};

#endif
