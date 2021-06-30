#include "GameEngine.h"
#include <iostream>

void GameEngine::update()
{
	gameCore->Update();
}

void GameEngine::draw()
{
	drawEngine->Draw();
}
