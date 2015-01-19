#ifndef DriveTrain_H
#define DriveTrain_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class DriveTrain: public Subsystem
{
private:
	SpeedController *drivefl;
	SpeedController *drivefr;
	SpeedController *drivebl;
	SpeedController *drivebr;
	RobotDrive *drive;

	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
public:
	DriveTrain();
	float GetMotorValue(int x);
	void InitDefaultCommand();
	void MecanumDrive(Joystick *joyl, Joystick *joyr);
	void TankDrive(Joystick *joyl, Joystick* joyr);
	void Stop();
};
#endif
