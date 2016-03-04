#pragma once

#include "Commands/Subsystem.h"

class SpeedController;

class ShootPlatform : public Subsystem {
private:
	SpeedController *front, *rear, *load;

public:
	ShootPlatform();
	~ShootPlatform();

	void InitDefaultCommand();

	/// @brief Set the power of the loading motors.
	void LoadPower(float power);

	/// @brief Set the power of the firing motors.
	void FirePower(float power_front, float power_rear);
};
