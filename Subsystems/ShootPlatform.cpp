#include "ShootPlatform.h"
#include "../RobotMap.h"
#include "../Commands/Shoot.h"

ShootPlatform::ShootPlatform() :
Subsystem("ShootPlatform") {
	shootforward = new Talon(ShootForward);
	shootback = new Talon(ShootBack);
	servoleft = new Servo(ServoLeft);
	servoright = new Servo(ServoRight);

}

void ShootPlatform::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new Shoot);
}

void ShootPlatform::ShootOI(JoystickButton* button1, JoystickButton* button2, JoystickButton* button3, JoystickButton* button4) {

	if(button4->Get()){
		shootforward->Set(1.0);
	}
	else if (button2->Get()){
		shootforward->Set(1.0);
		shootback->Set(-1.0);
	}

    if(button1->Get()){
		servoleft->Set(1.0);
		servoright->Set(-1.0);
	}
	else if (button3->Get()){
		servoleft->Set(-1.0);
		servoright->Set(1.0);
	}
}
