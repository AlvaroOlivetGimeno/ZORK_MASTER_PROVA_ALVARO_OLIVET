#pragma once
#include "DrawEngine.h"
#include "LluviaLetrasCore.h"

class GameEngine
{
	DrawEngine *drawEngine;
	LluviaLetrasCore *gameCore;

	bool executeNextFrame;

public:
	GameEngine(int boardSizeX, int boardSizeY)
	{
		drawEngine = new DrawEngine(boardSizeX, boardSizeY);
		gameCore = new LluviaLetrasCore(drawEngine);
		executeNextFrame = true;
	}

	~GameEngine()
	{
		delete drawEngine;
		delete gameCore;
	}


	void update();
	void draw();
};

