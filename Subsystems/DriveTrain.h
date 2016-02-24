#pragma once

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	SpeedController *driveleft;
	SpeedController *driveright;
	RobotDrive *drive;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveTrain();
	double GetMotorValue(int x);
	void InitDefaultCommand();
	void MecanumDrive(Joystick *joyl, Joystick *joyr, JoystickButton*  buttonleft, JoystickButton* buttonright, JoystickButton*  buttonleftf, JoystickButton* buttonrightf, JoystickButton* buttonfl, JoystickButton* buttonfr, JoystickButton* buttonbl, JoystickButton* buttonbr, JoystickButton* buttonslidel, JoystickButton* buttonslider);
	void TankDrive(Joystick *joyl, Joystick* joyr);
	void Stop();
	void TankDrivenum(float y1, float y2);
	//double Testing();
};
