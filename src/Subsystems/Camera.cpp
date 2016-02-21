#include "Camera.h"
#include "../RobotMap.h"

Camera::Camera() :
Subsystem("CameraSubsystem")
{
	imaqError = IMAQdxOpenCamera("cam0", IMAQdxCameraControlModeController, &session);
	frame = imaqCreateImage(IMAQ_IMAGE_RGB, 0);
		//the camera name (ex "cam0") can be found through the roborio web interface

		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxOpenCamera error: " + std::to_string((long)imaqError) + "\n");
		}
		imaqError = IMAQdxConfigureGrab(session);
		if(imaqError != IMAQdxErrorSuccess) {
			DriverStation::ReportError("IMAQdxConfigureGrab error: " + std::to_string((long)imaqError) + "\n");
		}
}

void Camera::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new MySpecialCommand());
	// create an image
	IMAQdxStartAcquisition(session);

	        // grab an image, draw the circle, and provide it for the camera server which will
	        // in turn send it to the dashboard.

				IMAQdxGrab(session, frame.get(), true, NULL);
				if(imaqError != IMAQdxErrorSuccess) {
					DriverStation::ReportError("IMAQdxGrab error: " + std::to_string((long)imaqError) + "\n");
				} else {
					imaqDrawShapeOnImage(frame.get(), frame.get(), { 10, 10, 100, 100 }, DrawMode::IMAQ_DRAW_VALUE, ShapeMode::IMAQ_SHAPE_OVAL, 0.0f);
					CameraServer::GetInstance()->SetImage(frame.get());
				}
				Wait(0.005);				// wait for a motor update time

	        // stop image acquisition
			IMAQdxStopAcquisition(session);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
