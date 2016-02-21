#include "StartCamera.h"

StartCamera::StartCamera()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(chassis);
}

// Called just before this Command runs the first time
void StartCamera::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void StartCamera::Execute()
{
	Robot::camera->InitDefaultCommand();
}

// Make this return true when this Command no longer needs to run execute()
bool StartCamera::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void StartCamera::End()
{

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void StartCamera::Interrupted()
{

}
