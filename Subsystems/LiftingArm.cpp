#include "LiftingArm.h"
#include "../RobotMap.h"
#include "../Commands/LiftUpDown.h"
#include <math.h>
LiftingArm::LiftingArm() :
		Subsystem("LiftingArm")
{

	armWinch = new Jaguar(LiftJagPWM);
	//Encoder Constructor and Raw Output.
	//encod = new Encoder(EncAChan, EncBChan, false, Encoder::k4X);
	//LiveWindow::GetInstance()->AddSensor("Lifting Arm", "Encoder", encod);


}

void LiftingArm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new LiftUpDown());
}
/*Encoder *LiftingArm::GetEncoder()
{
	return encod;
}*/
void LiftingArm::Up(float speed)
{
	armWinch->Set(-std::abs(speed));
}
void LiftingArm::Down(float speed)
{
	armWinch->Set(std::abs(speed));
}
void LiftingArm::Stop()
{
	armWinch->Set(0.0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
