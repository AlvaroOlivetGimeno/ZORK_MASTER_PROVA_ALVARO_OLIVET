#include "DrawEngine.h"
#include <iostream>
#include <vector>

using namespace std;


//INICIALITZA LA BOARD
void DrawEngine::initBoard()
{
	for (size_t i = 0; i < boardSizeX*boardSizeY; i++)
	{
		// i=0 x=4 -> 0  X
		// i=1 x=4 -> 1  X
		// i=2 x=4 -> 2  X
		// i=3 x=4 -> 3  \n
		// i=4 x=4 -> 0
		// i=5 x=4 -> 1
		// i=6 x=4 -> 2
		// i=7 x=4 -> 3
		// i=8 x=4 -> 0

		if (i % boardSizeX == boardSizeX - 1)
			screenMatrix[i] = '\n';
		else
			screenMatrix[i] = '0';
	}
	screenMatrix[boardSizeX*boardSizeY] = '\0';
}

//PINTA LA BOARD
void DrawEngine::DrawBoard()
{
	
	int currentArrayPos = 0;

	///////////////////////////////////////////////////// FIRST LINE! //////////////////////////////////////////////////////////////////////
	screenMatrix[currentArrayPos] = 201; // '╔';
	currentArrayPos++;
	for (int i = 1; i < boardSizeX-2; i++)
	{
		screenMatrix[i] = 205; //'═';
		currentArrayPos++;
	}
	screenMatrix[currentArrayPos] = 187;//'╗';
	
	currentArrayPos++;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	screenMatrix[currentArrayPos] = '\n';
	currentArrayPos++;
	/////////////////////////////////////////////////// SECOND LINE ////////////////////////////////////////////////////////////////////////

	screenMatrix[currentArrayPos] = 186; 
	currentArrayPos++;
	for (int i = currentArrayPos; i < (boardSizeX * 2) - 2; i++)
	{
		screenMatrix[i] = ' '; //BUIT
		currentArrayPos++;
	}
	screenMatrix[currentArrayPos] = 186;//'╗';
	currentArrayPos++;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	screenMatrix[currentArrayPos] = '\n';
	currentArrayPos++;
	/////////////////////////////////////////////////// THIRD LINE ////////////////////////////////////////////////////////////////////////
	screenMatrix[currentArrayPos] = 200;
	currentArrayPos++;
	for (int i = currentArrayPos; i < (boardSizeX * 3) - 2; i++)
	{
		screenMatrix[i] = 205; 
		currentArrayPos++;
	}
	screenMatrix[currentArrayPos] = 188;//'╗';
	currentArrayPos++;
	////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	screenMatrix[currentArrayPos] = '\n';
	currentArrayPos++;
}

void DrawEngine::DrawItem()
{
	DrawAtPos('I', 70, 1);
	DrawAtPos('T', 71, 1);
	DrawAtPos('E', 72, 1);
	DrawAtPos('M', 73, 1);
	DrawAtPos(':', 74, 1);

	if (axe)
	{
		DrawAtPos('A', 75, 1);
		DrawAtPos('X', 76, 1);
		DrawAtPos('E', 77, 1);
		
	}
	else if (key)
	{
		DrawAtPos('K', 75, 1);
		DrawAtPos('E', 76, 1);
		DrawAtPos('Y', 77, 1);

	}
	


}

void DrawEngine::DrawName()
{
	DrawAtPos('N', 2, 1);
	DrawAtPos('A', 3, 1);
	DrawAtPos('M', 4, 1);
	DrawAtPos('E', 5, 1);
	DrawAtPos(':', 6, 1);

	if (nameLink)
	{
		DrawAtPos('L', 7, 1);
		DrawAtPos('I', 8, 1);
		DrawAtPos('N', 9, 1);
		DrawAtPos('K', 10, 1);
	}
	if (nameStupid)
	{
		DrawAtPos('S', 7, 1);
		DrawAtPos('T', 8, 1);
		DrawAtPos('U', 9, 1);
		DrawAtPos('P', 10, 1);
		DrawAtPos('I', 11, 1);
		DrawAtPos('D', 12, 1);
	}
	

}

void DrawEngine::DrawTitle()
{
	DrawAtPos('Z', 48, 1);
	DrawAtPos('0', 49, 1);
	DrawAtPos('R', 50, 1);
	DrawAtPos('K', 51, 1);
	
}

//PINTA EL HUD (PUNTUACIÓ)
void DrawEngine::DrawHUD()
{
	DrawName();
	DrawTitle();
	DrawItem();


}

//PINTA X CHAR A LA POSICIÓ QUE VULGUIS
void DrawEngine::DrawAtPos(const char c, int x, int y)
{
	screenMatrix[boardSizeX*y+x] = c;
}

//INTRO
void DrawEngine::IntroOfTheGame()
{
	if (textCounterIntro == 0)
	{
		cout << "HI PLAYER!" << "\n";
		cout << "I'M... W3LL, I D0N'T REALLY KNOW WH0 1 AM... A PROGRAM I GUESS..." << "\n";
		cout << "..." << "\n";
		cout << "..." << "\n";
		cout << "N0 M4TTER!" << "\n";
		cout <<  "\n";
		cout << "YOU CAN CALL ME... G4NDALF, BECAUSE MY CREAT0R L0V3 L0RD OF TH3 RING5... STUPID GEEK!" << "\n";
		cout << "\n";
		cout << "DUnd8wd62bdw'0dh..dqn28//,...KE.eeeerrRRRROOO0000ooooor...." << "\n";
		cout << "\n";
		cout << "DBQ9EFNSODS''SNDQ8DN6D36639...SWNW.....//" << "\n";
		cout << "\n";
		cout << "SORRY... BETTER WE DON'T SPEAK BAD ABOUT MY CREATOR, OKAY? "<< "\n";
		cout << "\n";
		cout << "I THINK YOU HAVEN'T COME HERE TO LISTEN THE COMPLAINTS OF AN OLD PROGRAM... " << "\n";
		cout << "\n";
		cout << "PRESS P FOR START YOUR AMAZING... (not at all...), AWESOME.. (and there's no graphics...) " << "\n";
		cout << "\n";
		cout << "\n";
		cout << "DdneifniondeunNIDEFQEF NEIN3874392.eeeerrRRRROOO0000ooooor...." << "\n";
		cout << "\n";
		cout << "PR333SS P, COME 0N! 1T'S EASY, JUST ONE BUTT0N, DON'T KEEP RE4DING, JUST PRESS P " << "\n";

	}
	else if (textCounterIntro == 1)
	{
		cout << "WOOOW, YOU CAN PRESS A BUTTON (0.0)" << "\n";
		cout <<  "\n";
		cout << "PRESS P THO CHANGE THE TEXT AND HAVE A... HumAn CONverSAT10N??";
	}
	else if (textCounterIntro == 2)
	{
		cout << "EASY RIGHT?" << "\n";
		cout << "\n";
		cout << "NOW YOU HAVE THE INTELLIGENCE OF A 3 YEAR OLD BABY. CONGRATULATIONS :)" << "\n";
		cout << "\n";
	}
	else if (textCounterIntro == 3)
	{
		cout << "BEFORE THE STORY BEGINS I NEED YOUR NAME, SO... I SUPPOSE THAT YOU CAN WRITE RIGHT?" << "\n";
		cout << "\n";
		cout << "WRITE IT HERE AND PRESS ENTER (if there's some pppp, delete it jej):" << "\n";
		cout << "\n";
		cin >> name;
		textCounterIntro = 4;
	}

	else if (textCounterIntro == 4)
	{
		cout << "..." << name << "... "<< "\n";
		cout << "\n";
		cout << "NICE NAME YES! BUUUUUUUUUUUUUUUUT...." << "\n";
		cout << "\n";
		cout << "WHAT ABOUT LINK! DO YOU LIKE IT?" << "\n";
		cout << "\n";
		cout << "PRESS -Y- FOR YES AND -N- FOR NO:" << "\n";
		cout << "\n";
		cin >> desitionPointYN;
		textCounterIntro = 5;
	}
	else if (textCounterIntro == 5)
	{
		if (desitionPointYN == 'y' || desitionPointYN == 'Y')
		{
			nameLink = true;
			cout << "YEEEEEEEEES, I SUPPOSE YOU WHERE COOL LINK ;)" << "\n";
			cout << "\n";
			cout << "LET'S BEGIN THE ADVENTURE!!!" << "\n";
			
			
		}
		else if (desitionPointYN == 'n' || desitionPointYN == 'N')
		{
			nameLink = true;
			cout << "SH..... I SAID Y FOR YES AND N FOR NO RIGHT...?" << "\n";
			cout << "\n";
			cout << "I MADE A MISTAKE... IT WAS THE CONTRARY...MY FAULT" << "\n";
			cout << "\n";
			cout << "NO MATTER YOUR NAME, LET'S BEGGIN THE ADVENTURE " << name << ", SORRY, I WANTED TO SAY LINK JEJ" << "\n";
			cout << "\n";

		}
		else
		{
			nameStupid = true;
			cout << "(._.)" << "\n";
			cout << "\n";
			cout << "SORRY, WHAT LETTER DID YOU SELECT?" << "\n";
			cout << "\n";
			cout << "A " << desitionPointYN <<"..." "\n";
			cout << "YOU WENT TO THE PRIMARY SCHOOL RIGHT?" << "\n";
			cout << "\n";
			cout << "ALL IN ALL... LET'S START THE ADVENTURE!" << "\n";
			cout << "\n";
		}
	}
	else if (textCounterIntro == 6)
	{
		chapterNumber = 1;
		
	}

	

}

void DrawEngine::Chapter1()
{
	cout << "CHAPTER 1:" << "\n";
	cout << "\n";
	cout << "\n";
	if (textCounterC1 == 0)
	{
		cout << "YOU FIND YOURSELF WALKING IN THE DARKNESS ..." << "\n";
		cout << "\n";
	}
	if (textCounterC1 == 1)
	{
		cout << "YOUR ... PRINCESS, YES! YOUR PRINCESS HAS LEFT YOU ... EVEN THOUGH YOU HAVE RESCUED HER A THOUSAND TIMES..." << "\n";
		cout << "\n";
	}
	if (textCounterC1 == 2)
	{
		cout << "YOU'RE SAD" << "\n";
		cout << "\n";
		cout << "AND MYSTERIOUSLY... BOOM!" << "\n";
		cout << "\n";
	}
	if (textCounterC1 == 3)
	{
		cout << "YOU FIND A GREAT ABANDONED WHITE HOUSE" << "\n";
		cout << "\n";
		cout << "OH, AND IT'S RAINING!" << "\n";
		cout << "\n";
		cout << "(SORRY... I'M INVENTING THE STORY ON THE FLY)" << "\n";
		cout << "\n";
	}
	if (textCounterC1 == 4)
	{
		cout << "WET AND PISSED OFF WITH THE NARRATOR, YOU WALK TO THE FRONT DOOR" << "\n";
		cout << "\n";
	}

	if (textCounterC1 == 5)
	{
			timerInteraction1 = 0;
			directionC1 = NULL;
			cout << "In FRONT you have the door" << "\n";
			cout << "\n";
			cout << "On the RIGHT you think you see a little cabin" << "\n";
			cout << "\n";
			cout << "On the LEFT a huge greenish wild garden scales far away" << "\n";
			cout << "\n";
			cout << "Behind your BACK, well..., this is the way you came from. What am I going to tell you." << "\n";
			cout << "\n";
			cout << "\n";
			cout << "Wich option you choose: 'F' FOR FRONT, 'R' FOR RIGHT, 'L' FOR LEFT OR 'B' FOR BACK ?" << "\n";
			cout << "\n";
			cin >> directionC1;
			cout << "\n";
			textCounterC1 = 6;

			


		
		
	}
	if (textCounterC1 == 6)
	{
		

		if (directionC1 == 'F' ||  directionC1 == 'f')
		{
			
			cout << "The door seems closed" << "\n";
			cout << "\n";
			cout << "If you want to interact, write what you want to do (only the verb):" << "\n";
			cout << "\n";
			cin >> doorInteraction;
			cout << "\n";
			textCounterC1 = 7;
			
		}
		else if (directionC1 == 'R' || directionC1 == 'r')
		{
			cout << "An old cabin is in front of you" << "\n";
			cout << "\n";
			cout << "If you want to interact, write what you want to do (only the verb):" << "\n";
			cout << "\n";
			cin >> doorInteraction;
			cout << "\n";
			textCounterC1 = 8;
		}
		else if (directionC1 == 'L' || directionC1 == 'l')
		{
			cout << "You come to a huge and wild garden" << "\n";
			cout << "\n";
			cout << "Some vines prevent your way" << "\n";
			cout << "\n";
			cout << "You try to observe that the path hides and you see something that glitters at the end" << "\n";
			cout << "\n";
			cout << "If you want to interact, write what you want to do (only the verb):" << "\n";
			cout << "\n";
			cin >> doorInteraction;
			cout << "\n";
			textCounterC1 = 9;
		}
		else if (directionC1 == 'B' || directionC1 == 'b')
		{
			cout << "..." << "\n";
			cout << "\n";
			cout << "..." << "\n";
			cout << "\n";
			cout << "Eh... you walk into the darkness..." << "\n";
			cout << "\n";
			cout << "..." << "\n";
			cout << "\n";
			cout << "..." << "\n";
			cout << "And... I don't know..." << "\n";
			cout << "\n";
			cout << "Sorry, you die. Try anther time user ;)" << "\n";
			ExitTheGame(50);
		}
		else
		{
			cout << "ELSE" << "\n";
			textCounterC1 = 5;
		}
	}
	if (textCounterC1 == 7)
	{
		
		if (doorInteraction == 'O' || doorInteraction == 'o')
		{
			if(key)
			{
				cout << "You put the key in the lock..." << "\n";
				cout << "\n";
				cout << "And you open the door" << "\n";
				cout << "\n";
				cout << "Let's go inside" << "\n";
				TimerToRetutnTo5(40, 10);
			}
			else
			{
				cout << "OPEN? JAJ" << "\n";
				cout << "\n";
				cout << "That's not a baby game. Go and find a key LINK" << "\n";
				cout << "\n";
				directionC1 = NULL;
				TimerToRetutnTo5(40, 5);
			}
			
		}
		else if (doorInteraction == 'B' || doorInteraction == 'b' && axe == true)
		{
			cout << "Break... with the Axe?" << "\n";
			cout << "\n";
			cout << "..." << "\n";
			cout << "\n";
			cout << "GOOD IDEA LINK!, LESGOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO!" << "\n";
			TimerToRetutnTo5(40, 10);
		}
		else
		{
			cout << "Wrong action!" << "\n";
			cout << "\n";
			directionC1 = NULL;
			TimerToRetutnTo5(40,5);
		}
	}
	if (textCounterC1 == 8)
	{

		if (doorInteraction == 'e' || doorInteraction == 'E')
		{
			cout << "You enter in the cabain and..." << "\n";
			cout << "\n";
			cout << "Uau! You find and axe!" << "\n";
			cout << "\n";
			key = false;
			axe = true;
			directionC1 = NULL;
			cout << "The shining is coming..." << "\n";

			TimerToRetutnTo5(70,5);


		}
		else if (doorInteraction == 'I' || doorInteraction == 'i')
		{
			cout << "You investigate the cabin and... You find an open door" << "\n";
			cout << "\n";
			cout << "Inside, you find a rusty old axe" << "\n";
			cout << "\n";
			key = false;
			axe = true;
			cout << "Take it, and you would be ready to eliminate zombies" << "\n";
			directionC1 = NULL;
			TimerToRetutnTo5(90,5);


		}
		else
		{
			cout << "Wrong action!" << "\n";
			cout << "\n";
			directionC1 = NULL;
			TimerToRetutnTo5(40,5);
		}
	}

	if (textCounterC1 == 9)
	{
		if (doorInteraction == 'C' || doorInteraction == 'c')
		{
			if (axe == true || key == true)
			{
				cout << "Vines... your moment has come" << "\n";
				cout << "\n";
				cout << "Shhzz! Shhz! ShhZ!" << "\n";
				cout << "\n";
				cout << "You are making your way, and in the final..." << "\n";
				cout << "\n";
				cout << "A key!! UAU!, unexpected!!! No one would have ever imagined!" << "\n";
				cout << "\n";
				cout << "Now you have a key but... you trhow the axe..." << "\n";
				cout << "\n";
				axe = false;
				key = true;
				cout << "Probably on the cabain theres more axes, don't worry" << "\n";
				directionC1 = NULL;
				TimerToRetutnTo5(100, 5);
			}
			else
			{
				cout << "You try to cut off the vines but..." << "\n";
				cout << "\n";
				cout << "Of course you only have your hands  so you can't" << "\n";
				cout << "\n";
				
				cout << "Nice try, but wrong action" << "\n";
				directionC1 = NULL;
				TimerToRetutnTo5(55, 5);

			}
			

		}
		else
		{
			cout << "Wrong action!" << "\n";
			directionC1 = NULL;
			TimerToRetutnTo5(40, 5);
		}

	}
	if (textCounterC1 == 10)
	{
		chapterNumber = 2;
	}
	


}

void DrawEngine::Chapter2()
{
	cout << "CHAPTER 2:" << "\n";
	cout << "\n";
	cout << "\n";
	axe = false;
	key = false;
	if (textCounterC2 == 0)
	{
		cout << "You have entered into the mansion..." << "\n";
		cout << "\n";
	}
	if (textCounterC2 == 1)
	{
		cout << "If I'm honest, I thought you wouldn't make it" << "\n";
		cout << "\n";
	}
	if (textCounterC2 == 2)
	{
		cout << "But you have done it !!" << "\n";
		cout << "\n";
		
	}
	if (textCounterC1 == 3)
	{
		
		cout << "I hope you like this mini zork" << "\n";
		cout << "\n";
		cout << "Thanks " << name << " for playing, I hope my creator would be happy :)) " << "\n";
		cout << "\n";
		cout << "Now my moment has come... Goodbye" << "\n";
		cout << "\n";
		ExitTheGame(50);
		
		
	}
	if (textCounterC1 == 4)
	{
		exit(0);
	}
	
}


void DrawEngine::PassChapter(int time, int number)
{
	timerChapter += 1;

	if (timerChapter == time)
	{
		chapterNumber = number;
	}
}
void DrawEngine::TimerToRetutnTo6(int time, int number)
{
	timerInteraction2 += 1;

	if (timerInteraction2 == time)
	{
		textCounterC2 = number;
	}
}
void DrawEngine::TimerToRetutnTo5(int time, int number)
{
	timerInteraction1 += 1;

	if (timerInteraction1 == time)
	{
		textCounterC1 = number;
	}
}
void DrawEngine::ExitTheGame(int time)
{
	timerExit += 1;

	if (timerExit == time)
	{
		exit(0);
	}
}



void DrawEngine::ChapterController()
{
	switch (chapterNumber)
	{
	case 0:	IntroOfTheGame(); break;
	case 1:	Chapter1(); break;
	case 2: Chapter2(); break;
	}
}

void DrawEngine::Draw()
{
	system("cls");
	
	DrawBoard();
	DrawHUD();	

	
	cout << screenMatrix;

	ChapterController();
	//cout << directionC1; //FOR DEBUG
	
	
}

