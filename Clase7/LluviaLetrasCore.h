#pragma once
#include "DrawEngine.h"
#include "Windows.h"


class LluviaLetrasCore
{
	
	DrawEngine* drawE;

public:

	int timerForPassText  = 0;

	LluviaLetrasCore(DrawEngine *dE)
	{
		drawE = dE;
	}
	~LluviaLetrasCore()
	{
	
	}

	

	void PassTextSimpleFunction();

	void TimerForPassText();

	void Update();
};

