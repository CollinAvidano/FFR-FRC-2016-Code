#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "CommandBase.h"


class Robot: public IterativeRobot
{

	SendableChooser autoChooser;

private:
	DriveTrain *drivetrain;
	OI *oi;
	Command *autonomousCommand;
	LiveWindow *lw;

	void RobotInit()
	{
		CommandBase::init();
		SmartDashboard::PutData(drivetrain);
		autoChooser = new SendableChooser();
		//autoChooser.addDefault("Default program", new  DriveForward());
		//autoChooser.addObject("Difficult Mode", new PickupAuto());


		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
	}

	void AutonomousInit()
	{
		autonomousCommand = (Command) autoChooser.GetSelected();
		if (autonomousCommand != NULL)
			autonomousCommand->Start();
	}

	void AutonomousPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
	}

	void TeleopInit()
	{
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
	}

	void TestPeriodic()
	{
		lw->Run();
		Log();
	}
	void Log()
	{
		SmartDashboard::PutNumber("Left Front Motor", drivetrain->GetMotorValue(1l));
		SmartDashboard::PutNumber("Right Front Motor", drivetrain->GetMotorValue(2));
		SmartDashboard::PutNumber("Left Back Motor", drivetrain->GetMotorValue(3));
		SmartDashboard::PutNumber("Left Back Motor", drivetrain->GetMotorValue(4));
		SmartDashboard::PutNumber("Left Joystick X Axis", oi->GetLeftjoy()->GetX());
		SmartDashboard::PutNumber("Right Joystick X Axis", oi->GetRightjoy()->GetX());
		SmartDashboard::PutNumber("Left Joystick Y Axis", oi->GetLeftjoy()->GetY());
		SmartDashboard::PutNumber("Left Joystick Y Axis", oi->GetRightjoy()->GetY());
	}
};

START_ROBOT_CLASS(Robot);

