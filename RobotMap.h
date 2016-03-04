#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */
 
// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
const int LeftDrive = 0;
const int RightDrive = 1;
//const int LeftBackDrive = 2;
//const int RightBackDrive = 3;

const int ShootRear = 2; // Previously ShootInterior
const int ShootFront = 3; // Previously ShootExterior
const int Loader = 4;

const int LiftJagPWM = 6;
const int EncAChan = 0;
const int EncBChan = 1;
const float winchspeed = 1.0;
const float winchinc = 0.1;
const float winchthresh = 0.05;
const int GraspJagPWM = 5;
const float screwVal = 1.0;
const float turnRate = 0.2;
const float turnRatef = 0.5;
const float sidethresh = 0.10;
const float forwardrate = 0.2;
const float backwardrate = -0.2;
const float slideRate = 0.3;
const float autonomousTime = 12.5;
// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
//const int RANGE_FINDER_PORT = 1;
//const int RANGE_FINDER_MODULE = 1;
