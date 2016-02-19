#ifndef Record_H
#define Record_H

#include "../CommandBase.h"
#include "WPILib.h"

class Record: public CommandBase
{
public:
	Record();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
