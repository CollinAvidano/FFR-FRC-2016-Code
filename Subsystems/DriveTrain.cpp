#include "DriveTrain.h"
#include "../RobotMap.h"
#include "../Commands/DrivewithJoystick.h"

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

	drive->SetSafetyEnabled(false);
	drive->SetExpiration(0.1);
	drive->SetSensitivity(0.5);
	drive->SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearLeftMotor, true);
	drive->SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	drive->SetInvertedMotor(RobotDrive::kRearRightMotor, true);


}

void DriveTrain::MecanumDrive(Joystick* joyl, Joystick* joyr, JoystickButton* buttonleft, JoystickButton* buttonright, JoystickButton* buttonleftf, JoystickButton* buttonrightf, JoystickButton* buttonfl, JoystickButton* buttonfr, JoystickButton* buttonbl, JoystickButton* buttonbr, JoystickButton* buttonslidel, JoystickButton* buttonslider)
{
	float backwards = backwardrate;
	float forwards = forwardrate;
	float turns = turnRate;
	float turnsf = turnRatef;
	float slider = slideRate;
	forwards = SmartDashboard::GetNumber("Forward Button Speed", forwardrate);
	backwards = SmartDashboard::GetNumber("Backwards Button Speed", backwardrate);
	turns = SmartDashboard::GetNumber("Turn Buttons Slow Speed", turnRate);
	turnsf = SmartDashboard::GetNumber("Turn Buttons Fast Speed", turnRatef);
	slider = SmartDashboard::GetNumber("Slide Button Speed", slideRate);





				if(joyl->GetY() >=- sidethresh && joyl->GetY() <= sidethresh && joyr->GetY() <= sidethresh  && joyr->GetY() >= -sidethresh){
					if(joyl->GetX() >= sidethresh || joyl->GetX() <= -sidethresh || joyr->GetX() <= -sidethresh || joyr->GetX() >= sidethresh){
				drivefl->Set((-1.0) *joyl->GetX());
				driveflval = -joyl->GetX();
				drivefr->Set((-1.0) * joyl->GetX());
				drivefrval = joyl->GetX();
				drivebl->Set(joyl->GetX());
				driveblval = joyl->GetX();
				drivebr->Set( joyl->GetX());
				drivebrval = -joyl->GetX();
				}
					else if (buttonleft->Get() || buttonright->Get())
									{
										if(buttonleft->Get())
										{
											drivefl->Set(turns);
											drivebl->Set(turns);
											drivefr->Set(turns);
											drivebr->Set(turns);
										}
										else
										{
											drivefl->Set(-turns);
											drivebl->Set(-turns);
											drivefr->Set(-turns);
											drivebr->Set(-turns);
										}
									}
					else if (buttonleftf->Get() || buttonrightf->Get())
														{
															if(buttonleftf->Get())
															{
																drivefl->Set(turnsf);
																drivebl->Set(turnsf);
																drivefr->Set(turnsf);
																drivebr->Set(turnsf);
															}

															else
															{
																drivefl->Set(-turnsf);
																drivebl->Set(-turnsf);
																drivefr->Set(-turnsf);
																drivebr->Set(-turnsf);
															}
														}
					else if (buttonfl->Get() || buttonfr->Get())
																			{
																					drivefl->Set(-forwards);
																					drivefr->Set(forwards);
																					drivebl->Set(-forwards);
																					drivebr->Set(forwards);
																			}
					else if (buttonbl->Get() || buttonbr->Get())
																			{
																					drivefl->Set(-backwards);
																					drivefr->Set(backwards);
																					drivebl->Set(-backwards);
																					drivebr->Set(backwards);
																			}
					else if (buttonslidel->Get() || buttonslider->Get())
					{
																	if (buttonslidel->Get())
																			{
																					drivefl->Set(slider);
																					drivefr->Set(slider);
																					drivebl->Set(-slider);
																					drivebr->Set(-slider);
																			}
																	else
																	{
																		drivefl->Set(-slider);
																		drivefr->Set(-slider);
																		drivebl->Set(slider);
																		drivebr->Set(slider);
																	}
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
	float flval = 1.05;
	//double frval = drivefr->Get();
	//double blval = drivebl->Get();
	//double brval = drivebr->Get();
	//flval = static_cast <double> (drivefl->Get());
	std::cout<<"GetMotorValue Value:" <<flval<<std::endl;
	//frval = static_cast <double> (drivefr->Get());
	//blval = static_cast <double> (drivebl->Get());
	//brval = static_cast <double> (drivebr->Get());
		switch (x)
		{
		case 1:
		output = flval;
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
			//return 0.0;
			output = 0.0;
			break;
		}
		return output;
}
/*double DriveTrain::Testing()
	{
		double testval = 1.050;
		return testval;
	}*/



// Put methods for controlling this subsystem
// here. Call these from Commands.
