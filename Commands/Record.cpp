#include "Record.h"
#include "WPILib.h"

/*IMAQdxSession session;
Image *frame;
IMAQdxError imaqError;*/

Record::Record()
{
	Requires(cam);
}

// Called just before this Command runs the first time
void Record::Initialize()
{
	/*//camera update image creation
	// create an image
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
	//the camera name (ex "cam0") can be found through the roborio web interface
	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
	}
	imaqError = IMAQdxConfigureGrab(session);
	if(imaqError != IMAQdxErrorSuccess) {
		DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
	}*/
}

// Called repeatedly when this Command is scheduled to run
void Record::Execute()
{
	/*// acquire images
	IMAQdxStartAcquisition(session);

	// grab an image, draw the circle, and provide it for the camera server which will
	// in turn send it to the dashboard.
	while(true) {
		IMAQdxGrab(session, frame, true, NULL);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
		} else {
			CameraServer::GetInstance()->SetImage(frame);
		}
	}*/
}

// Make this return true when this Command no longer needs to run execute()
bool Record::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void Record::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Record::Interrupted()
{

}
