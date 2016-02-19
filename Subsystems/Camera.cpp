#include "Camera.h"
#include "../RobotMap.h"
#include "../Commands/Record.h"

Camera::Camera() :
		Subsystem("Camera")
{

}

void Camera::InitDefaultCommand()
{
	SetDefaultCommand(new Record);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

