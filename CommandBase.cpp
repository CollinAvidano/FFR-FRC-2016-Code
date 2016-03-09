#include "CommandBase.h"
#include "Commands/Scheduler.h"

// Initialize a single static instance of all of your subsystems to NULL

 DriveTrain* CommandBase::drivetrain = nullptr;
 OI* CommandBase::oi = nullptr;
 ShootPlatform* CommandBase::shootplatform = nullptr;

CommandBase::CommandBase(char const *name) :
		Command(name)
{
}

CommandBase::CommandBase() :
		Command()
{

}

void CommandBase::init()
{
	// Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.

	drivetrain =  new DriveTrain();
	oi = new OI();
	shootplatform = new ShootPlatform();
}
