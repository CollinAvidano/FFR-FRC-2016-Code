#include "Shoot.h"
#include "../OI.h"
#include "../Subsystems/ShootPlatform.h"

Shoot::Shoot(){
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(shootplatform);
}

// Called just before this Command runs the first time
void Shoot::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Shoot::Execute() {
	shootplatform->ShootOI(oi->GetButton1(), oi->GetButton2(), oi->GetButton3(), oi->GetButton4());
}

// Make this return true when this Command no longer needs to run execute()
bool Shoot::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void Shoot::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Shoot::Interrupted() {

}
