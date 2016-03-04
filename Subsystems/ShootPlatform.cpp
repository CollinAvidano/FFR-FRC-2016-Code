#include "ShootPlatform.h"

#include "../Commands/Shoot.h"
#include "../RobotMap.h"

#include <Talon.h>

ShootPlatform::ShootPlatform() :
Subsystem("ShootPlatform"), front(new Talon(ShootFront)),
rear(new Talon(ShootRear)), load(new Talon(Loader)) {

}

ShootPlatform::~ShootPlatform() {
	delete front;
	delete rear;
	delete load;
}

void ShootPlatform::InitDefaultCommand() {
	SetDefaultCommand(new Shoot());
}

void ShootPlatform::LoadPower(float power) {

}

void ShootPlatform::FirePower(float power_front, float power_rear) {
	front->Set(power_front, 0); // Syncgroup 0 to update immediately
	rear->Set(power_rear, 0);
}

