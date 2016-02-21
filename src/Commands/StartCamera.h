#ifndef StartCamera_H
#define StartCamera_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class StartCamera: public Command
{
public:
	StartCamera();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
