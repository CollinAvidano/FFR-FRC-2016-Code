#ifndef LiftingArm_H
#define LiftingArm_H

#include "Commands/Subsystem.h"
#include "WPILib.h"

class LiftingArm: public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	SpeedController *armWinch;
	//Encoder *encod;
public:
	LiftingArm();
	void InitDefaultCommand();
	//Encoder *GetEncoder();
	void Up(float speed);
	void Down(float speed);
	void Stop();
};

#endif
