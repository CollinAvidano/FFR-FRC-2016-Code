#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick *leftjoy;
	Joystick *rightjoy;
	Joystick *gamecon;
	JoystickButton *buttonleft;
	JoystickButton *buttonright;
	JoystickButton *buttonleftf;
	JoystickButton *buttonrightf;
	JoystickButton *buttonopen;
	JoystickButton *buttonclose;
	JoystickButton *buttonforwardl;
	JoystickButton *buttonbackwardl;
	JoystickButton *buttonforwardr;
	JoystickButton *buttonbackwardr;
	JoystickButton *buttonsl;
	JoystickButton *buttonsr;
public:
	OI();
	Joystick* GetLeftjoy();
	Joystick* GetRightjoy();
	JoystickButton* GetButtonLeft();
	JoystickButton* GetButtonRight();
	JoystickButton* GetButtonLeftf();
	JoystickButton* GetButtonRightf();
	Joystick* GetGameCon();
	JoystickButton* GetButtonOpen();
	JoystickButton* GetButtonClose();
	JoystickButton* GetButtonFl();
	JoystickButton* GetButtonFr();
	JoystickButton* GetButtonBl();
	JoystickButton* GetButtonBr();
	JoystickButton* GetButtonSl();
	JoystickButton* GetButtonSr();

};

#endif
