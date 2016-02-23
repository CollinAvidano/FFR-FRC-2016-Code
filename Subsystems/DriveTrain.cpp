#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/DrivewithJoystick.h"


DriveTrain::DriveTrain() :
		Subsystem("DriveTrain")
{
	driveL = new Talon(LeftDrive);
	driveR = new Talon(RightDrive);
	drive = new RobotDrive (driveL, driveR);

	drive->SetSafetyEnabled(false);
	drive->SetExpiration(0.1);
	drive->SetSensitivity(0.5);

	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);


}

void DriveTrain::TankDrive(Joystick *joyl, Joystick *joyr)
{
	drive->TankDrive(joyl->GetY(), joyr->GetY());
}

void DriveTrain::TankDrivenum(float y1, float y2)
{
	drive->TankDrive(y1, y2);
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

double DriveTrain::GetMotorValue(int x)
{
	//std::cout << "Is it after here?" << std::endl;
	double output;
//	float flval = 1.05;
	//double frval = drivefr->Get();
	//double blval = drivebl->Get();
	//double brval = drivebr->Get();
	//flval = static_cast <double> (drivefl->Get());
//	std::cout<<"GetMotorValue Value:" <<flval<<std::endl;
	//frval = static_cast <double> (drivefr->Get());
	//blval = static_cast <double> (drivebl->Get());
	//brval = static_cast <double> (drivebr->Get());
		switch (x)
		{
		case 1:
		output = 0.0;
			break;
		case 2:
			return 0.0;
			break;
		case 3:
			return driveL->Get();
			break;
		case 4:
			return driveR->Get();
			break;
		default:
			output = 0.0;
			break;
		}
		return output;
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
