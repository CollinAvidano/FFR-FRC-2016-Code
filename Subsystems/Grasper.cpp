#include "Grasper.h"
#include "../RobotMap.h"
#include "Commands/GraspOpenClose.h"

Grasper::Grasper() :
		Subsystem("ExampleSubsystem")
{
 screw = new Jaguar(GraspJagPWM);
}

void Grasper::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new GraspOpenClose);
}

void Grasper::Open()
{
	screw->Set(screwVal);
}
 void Grasper::Close()
{
	screw->Set(-screwVal);
}
void Grasper::Stop()
{
	screw->Set(0.0);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
