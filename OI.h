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
	JoystickButton *button1;
	JoystickButton *button2;
	JoystickButton *button3;
	JoystickButton *button4;
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

	JoystickButton* GetButton1();
	JoystickButton* GetButton2();
	JoystickButton* GetButton3();
	JoystickButton* GetButton4();

	JoystickButton* GetButtonFl();
	JoystickButton* GetButtonFr();
	JoystickButton* GetButtonBl();
	JoystickButton* GetButtonBr();
	JoystickButton* GetButtonSl();
	JoystickButton* GetButtonSr();

};

#endif
