#include "MoveForward.h"
#include "../RobotMap.h"

bool done;
MoveForward::MoveForward()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(drivetrain);
}

// Called just before this Command runs the first time
void MoveForward::Initialize()
{
	done = false;
}

// Called repeatedly when this Command is scheduled to run
void MoveForward::Execute()
{

      drivetrain->TankDrivenum(-0.5, 0.5);
      Wait(autonomousTime);
      drivetrain->Stop();
      done = true;
}

// Make this return true when this Command no longer needs to run execute()
bool MoveForward::IsFinished()
{
	if (done)
	{
		return true;
	}
	else
	{
	return false;
	}
}

// Called once after isFinished returns true
void MoveForward::End()
{
	drivetrain->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void MoveForward::Interrupted()
{
 End();
}
