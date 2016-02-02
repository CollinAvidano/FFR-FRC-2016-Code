#include "GraspOpenClose.h"

GraspOpenClose::GraspOpenClose()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(grasp);
}

// Called just before this Command runs the first time
void GraspOpenClose::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void GraspOpenClose::Execute()
{
	if (oi->GetButtonOpen()->Get())
	{
		grasp->Open();
	}
	else if(oi->GetButtonClose()->Get())
	{
		grasp->Close();
	}
	else
	{
		grasp->Stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool GraspOpenClose::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void GraspOpenClose::End()
{
	grasp->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void GraspOpenClose::Interrupted()
{
	End();
}
