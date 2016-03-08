#include "LiftUpDown.h"

#include "../Subsystems/LiftingArm.h"
#include "../OI.h"

LiftUpDown::LiftUpDown()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
	Requires(lift);

}

// Called just before this Command runs the first time
void LiftUpDown::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void LiftUpDown::Execute()
{
	/*float speed = 0;
	int ispos = 0;
	if(oi->GetButtonUp()->Get())
	{
		ispos = 1;
		if(speed < winchspeed)
		{
		for(float i = speed; i <= winchspeed;  i += winchinc)
		{
			speed = i;
			if (speed < winchspeed)
			{


		lift->Up(i);
		}
		else
		{
			lift->Up(winchspeed);
		}
		}
		}
		else
		{
			lift->Up(winchspeed);
		}
	}
	else if(oi->GetButtonDown()->Get())
	{
			ispos = -1;
			if(speed < winchspeed)
			{
			for(float i = speed; i <= winchspeed;  i += winchinc)
			{
				speed = i;
				if (speed < winchspeed)
				{
			lift->Down(i);
			}
			else
			{
				lift->Down(winchspeed);
			}
			}
			}
			else
			{
				lift->Down(winchspeed);
			}
		}
	else if (speed > winchinc && ispos == 1 && !(oi->GetButtonUp()->Get() && oi->GetButtonDown()->Get()) )
	{
		for(float i = speed; i > 0;  i -=  winchinc)
		{
			speed = i;
		lift->Up(i);
		}
	}
	else if (speed  > winchinc && ispos == -1 && !(oi->GetButtonUp()->Get() && oi->GetButtonDown()->Get()))
	{
		for(float i = speed; i >0; i -= winchinc)
		{
			lift->Down(i);
		}
	}
	else if (speed <= winchinc )
	{
		lift->Stop();
	}
	else
	{
		lift->Stop();
	}*/
	if(std::abs(oi->GetGameCon()->GetY()) >= winchthresh && oi->GetGameCon()->GetY() < 0)
	{
		lift->Up(oi->GetGameCon()->GetY() * winchspeed);
	}
	else if (std::abs(oi->GetGameCon()->GetY()) >= winchthresh)
	{
		lift->Down(oi->GetGameCon()->GetY() * (winchspeed - 0.1));
	}
	else
	{
		lift->Stop();
	}
}


// Make this return true when this Command no longer needs to run execute()
bool LiftUpDown::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void LiftUpDown::End()
{
	lift->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftUpDown::Interrupted()
{
	End();
}
