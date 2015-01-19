#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick *leftjoy;
	Joystick *rightjoy;
public:
	OI();
	Joystick* GetLeftjoy();
	Joystick* GetRightjoy();

};

#endif
