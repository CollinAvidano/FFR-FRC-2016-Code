#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	SpeedController *driveL;
	SpeedController *driveR;
	RobotDrive *drive;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveTrain();
	double GetMotorValue(int x);
	void InitDefaultCommand();
	void TankDrive(Joystick *joyl, Joystick* joyr);
	void Stop();
	void TankDrivenum(float y1, float y2);
	//double Testing();
};
#endif
