#pragma once

#include <Commands/Subsystem.h>
#include "WPILib.h"

class DriveTrain: public Subsystem {
private:
	SpeedController *driveleft;
	SpeedController *driveright;
	RobotDrive *drive;

public:
	DriveTrain();
	double GetMotorValue(int x);
	void InitDefaultCommand();
	void TankDrive(Joystick *joyl, Joystick* joyr);
	void Stop();
	void TankDrivenum(float y1, float y2);
	//double Testing();
};
