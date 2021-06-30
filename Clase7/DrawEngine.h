#pragma once
#include <vector>
#include <iostream>
#include <string>

class DrawEngine
{
	char* screenMatrix;
	void DrawBoard();
	void DrawItem();
	void DrawHUD();
	void DrawName();
	void DrawTitle();

public:

	int boardSizeX;
	int boardSizeY;
	char* snakeMatrix;

	bool nameLink = false;
	bool nameStupid = false;
	bool principalDoorOpen = false;
	char name[20];
	char likeTheGame[20];
	char directionC1;
	char doorInteraction;
	int timerInteraction1;
	int timerInteraction2;
	int timerExit;
	int timerChapter;
	char desitionPointYN;
	

	//ITEMS
	bool axe;
	bool key;

	int chapterNumber = 0;
	int textCounterIntro = 0;
	int textCounterC1 = 0;
	int textCounterC2 = 0;

	

	void initBoard();

	DrawEngine(int x, int y) : boardSizeX(x+1), boardSizeY(y)
	{
		screenMatrix = new char[((x+1)*y)+1]; 
		initBoard();
	}

	~DrawEngine() {}


	void DrawAtPos(const char c, int x, int y);
	void IntroOfTheGame();
	void Chapter1();

	void Chapter2();

	void PassChapter(int time, int number);

	void TimerToRetutnTo6(int time, int number);

	void TimerToRetutnTo5(int time, int number);
	void ExitTheGame(int time);
	void ChapterController();
	void Draw();

};


