#ifndef ShootingArm_H
#define ShootingArm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class ShootingArm : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	SpeedController *ArmMotor1;
	SpeedController *ArmMotor2;
	SpeedController *ArmMotor3;

public:
	ShootingArm();
	void InitDefaultCommand();
	void Up(float speed);
	void Down(float speed);
	void Stop();
};

#endif
