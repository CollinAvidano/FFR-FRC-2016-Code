#include "ShootingArm.h"
#include "../Commands/shoot.h"
#include "../RobotMap.h"
#include <math.h>

ShootingArm::ShootingArm() :
		Subsystem("ShootingArm")
{
	ArmMotor1 = new Jaguar(ArmJagPWM1);
	ArmMotor2 = new Jaguar(ArmJagPWM2);
	ArmMotor3 = new Jaguar(ArmJagPWM3);
}

void ShootingArm::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Shoot);
}
void ShootingArm::Up(float speed)
{
	ArmMotor1->Set(-std::abs(speed));
	ArmMotor2->Set(-std::abs(speed));
	ArmMotor3->Set(-std::abs(speed));
}
void ShootingArm::Down(float speed)
{
	ArmMotor1->Set(std::abs(speed));
	ArmMotor2->Set(std::abs(speed));
	ArmMotor3->Set(std::abs(speed));
}
void ShootingArm::Stop()
{
	ArmMotor1->Set(std::abs(0.0));
	ArmMotor2->Set(std::abs(0.0));
	ArmMotor3->Set(std::abs(0.0));
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
