#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Commands/DrivewithJoystick.h"

	double driveflval;
	double drivefrval;
	double driveblval;
	double drivebrval;

DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
	drivefl = new Talon(LeftFrontDrive);
	drivefr = new Talon(RightFrontDrive);
	drivebl = new Talon(LeftBackDrive);
	drivebr = new Talon(RightBackDrive);
	drive = new RobotDrive (drivefl, drivebl, drivefr, drivebr);

	drive->SetSafetyEnabled(true);
	drive->SetExpiration(0.1);
	drive->SetSensitivity(0.5);
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, false);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);

}

void DriveTrain::MecanumDrive(Joystick* joyl, Joystick* joyr)
{


				if(joyl->GetY() >=- 0.2 && joyl->GetY() <= 0.2 && joyr->GetY() <= 0.2  && joyr->GetY() >= -0.2){
					if(joyl->GetX() >= 0.2 || joyl->GetX() <= -0.2 || joyr->GetX() <= -0.2 || joyr->GetX() >= 0.2){
				drivefl->Set(-joyl->GetX());
				driveflval = -joyl->GetX();
				drivefr->Set(joyl->GetX());
				drivefrval = joyl->GetX();
				drivebl->Set(joyl->GetX());
				driveblval = joyl->GetX();
				drivebr->Set(-joyl->GetX());
				drivebrval = -joyl->GetX();
				}
					else
					{
						drivefl->Set(0.0);
						driveflval = 0.0;
						drivefr->Set(0.0);
						drivefrval = 0.0;
						drivebl->Set(0.0);
						driveblval = 0.0;
						drivebr->Set(0.0);
						drivebrval = 0.0;
					}
				}
				/*else if (joyr->GetX()  <=  -.15){
					drivefl->Set( joyr->GetX());
					drivefr->Set(- joyr->GetX());
					drivebl->Set(- joyr->GetX());
					drivebr->Set( joyr->GetX());
				}*/
				else {
					drivefl->Set(joyl->GetY());
					driveflval = joyl->GetY();
					drivefr->Set(joyr->GetY() * -1.0);
					drivefrval = -joyr->GetY();
					drivebl->Set(joyl->GetY());
					driveblval = joyl->GetY();
					drivebr->Set(joyr->GetY() * -1.0);
					drivebrval= joyr->GetY();
				}

			}

void DriveTrain::TankDrive(Joystick *joyl, Joystick *joyr)
{
	drive->TankDrive(joyl->GetY(), joyr->GetY());
}



void DriveTrain::InitDefaultCommand()
{
	SetDefaultCommand(new DrivewithJoystick);
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
}
void DriveTrain::Stop()
{
	drive->TankDrive(0.0, 0.0);
}

float DriveTrain::GetMotorValue(int x)
{
		switch (x)
		{
		case 1:
			return drivefl->Get();
			break;
		case 2:
			return drivefr->Get();
			break;
		case 3:
			return drivebl->Get();
			break;
		case 4:
			return drivebr->Get();
			break;
		default:
			return 0.0;
			break;
		}

}


// Put methods for controlling this subsystem
// here. Call these from Commands.
