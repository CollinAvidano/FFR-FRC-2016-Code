#pragma once

#include <Commands/Command.h>

class DriveTrain;
class OI;
class LiftingArm;
class Camera;
class ShootPlatform;

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase : public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	virtual ~CommandBase() {}
	static void init();
	// Create a single static instance of all of your subsystems
    static DriveTrain *drivetrain;
	static OI *oi;
	static LiftingArm *lift;
	static ShootPlatform *shootplatform;
};
