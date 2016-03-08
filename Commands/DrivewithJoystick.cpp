#include "DrivewithJoystick.h"
#include "../Subsystems/DriveTrain.h"
#include "../OI.h"

DrivewithJoystick::DrivewithJoystick()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void DrivewithJoystick::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void DrivewithJoystick::Execute()
{
	 drivetrain->TankDrive(oi->GetLeftjoy(),oi->GetRightjoy());
}

// Make this return true when this Command no longer needs to run execute()
bool DrivewithJoystick::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void DrivewithJoystick::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DrivewithJoystick::Interrupted()
{
	End();
}
