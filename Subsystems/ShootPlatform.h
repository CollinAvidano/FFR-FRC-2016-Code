#pragma once

#include <Commands/Subsystem.h>
#include "WPILib.h"

class ShootPlatform : public Subsystem {
private:
	SpeedController *shootforward;
	SpeedController *shootback;
	Servo *servoleft;
	Servo *servoright;

public:
	ShootPlatform();
	void InitDefaultCommand();
	void ShootOI(JoystickButton* button1, JoystickButton* button2, JoystickButton* button3, JoystickButton* button4);
};
