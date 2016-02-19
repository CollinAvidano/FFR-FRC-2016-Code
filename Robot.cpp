#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/DriveTrain.h"
#include "Subsystems/LiftingArm.h"
#include "CommandBase.h"
#include <string.h>
#include "RobotMap.h"
#include "Commands/MoveForward.h"
class Robot: public IterativeRobot
{

private:
	//SendableChooser *autoChooser;
	DriveTrain *drivetrain;
	OI *oi;
	LiftingArm *lift;
	Camera *cam;

	BuiltInAccelerometer *accel;
	Command *autonomousCommand;
	LiveWindow *lw;
	IMAQdxSession session;
	Image *frame;
	IMAQdxError imaqError;


	void RobotInit()
	{
		CommandBase::init();
		SmartDashboard::init();
		accel = new BuiltInAccelerometer;
		//SmartDashboard::PutData(drivetrain);
		//autoChooser = new SendableChooser();
		//autoChooser->AddDefault("Default program", new  DriveForward());
		//autoChooser->AddObject("Difficult Mode", new PickupAuto());
		//SmartDashboard::PutData("Autonomous modes", autoChooser);

		lw = LiveWindow::GetInstance();
	}
	
	void DisabledPeriodic()
	{
		Scheduler::GetInstance()->Run();

	}

	void AutonomousInit()
	{
		//autonomousCommand = (Command *) autoChooser->GetSelected();
		autonomousCommand = new MoveForward;
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
		SmartDashboard::PutNumber("Forward Button Speed", forwardrate);
		SmartDashboard::PutNumber("Backwards Button Speed", backwardrate);
		SmartDashboard::PutNumber("Turn Buttons Slow Speed", turnRate);
		SmartDashboard::PutNumber("Turn Buttons Fast Speed", turnRatef);
		SmartDashboard::PutNumber("Slide Button Speed", slideRate);

		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (autonomousCommand != NULL)
			autonomousCommand->Cancel();

		CameraServer::GetInstance()->SetQuality(50);
		CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	}

	void TeleopPeriodic()
	{
		Scheduler::GetInstance()->Run();
		Log();
		lw->Run();
	}

	void TestPeriodic()
	{
		lw->Run();
		Log();
	}

	void Log()
	{

	}

};

START_ROBOT_CLASS(Robot);

