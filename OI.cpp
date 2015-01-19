#include "OI.h"
#include "WPILib.h"
OI::OI()
{
	// Process operator interface input here.
	leftjoy = new  Joystick(0);
	rightjoy = new Joystick(1);

}

	Joystick* OI::GetLeftjoy() {
		return leftjoy;
	}
	Joystick* OI::GetRightjoy() {
		return rightjoy;
	}

