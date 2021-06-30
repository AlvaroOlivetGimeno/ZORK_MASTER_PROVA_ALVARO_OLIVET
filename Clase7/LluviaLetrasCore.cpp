#include "LluviaLetrasCore.h"
#include <iostream>
#include "Helpers.h"
#include "DrawEngine.h"
#include "Windows.h"
#include <vector>
using namespace std;

void LluviaLetrasCore::PassTextSimpleFunction()
{
	switch (drawE->chapterNumber)
	{
		case 0:
		if (GetKeyState('P') & 0x8000 && timerForPassText>=3)
		{
			drawE->textCounterIntro++;
			timerForPassText = 0;
		}
		break;
		case 1:
			if (GetKeyState('P') & 0x8000 && timerForPassText >= 3)
			{
				drawE->textCounterC1++;
				timerForPassText = 0;
			}
			break;
		case 2:
			if (GetKeyState('P') & 0x8000 && timerForPassText >= 5)
			{
				drawE->textCounterC2++;
				timerForPassText = 0;
			}
			break;

	}


	
}

void LluviaLetrasCore::TimerForPassText()
{
	timerForPassText++;
}


//UPDATE
void LluviaLetrasCore::Update()
{
	
	PassTextSimpleFunction();
	
	TimerForPassText();
	

	
}

