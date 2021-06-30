#include <iostream>
#include "GameEngine.h"
#include "Windows.h"
#include "TimeManager.h"

int main()
{
	float timePerFrame = 0.2f;
	int gameBoardSizeX = 100;
	int gameBoardSizeY = 3;

	TimeManager *timeManager = new TimeManager(timePerFrame);
	GameEngine *engine = new GameEngine(gameBoardSizeX, gameBoardSizeY);
	bool executeLoop = true;

	while (executeLoop)
	{
		if (timeManager->shouldExtecuteNextFrame())
		{
			engine->update();
			engine->draw();
		}

		if (GetKeyState(VK_ESCAPE) & 0x8000)
			executeLoop = false;
	}

	delete timeManager;
	delete engine;
}




