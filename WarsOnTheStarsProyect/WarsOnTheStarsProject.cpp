// WarsOnTheStarsProject.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
#include "Engine.h"
#include "Background.h"
#include "FAriasSimpleGraphics.h"
#include "Player.h"
#include "LoginScreen.h"
#include "Stars.h"
#include "Enemies.h"
#include "Menu.h"
#include "Difficulty.h"
#include "HowToPlay.h"
#include "End.h"
#include "Victoria.h"

HANDLE hndl;

extern Game game;
extern FASG::WAVESound finalBossSong;

int main()
{	
	srand(time(NULL));
	game.W = 300; game.H = 60;

	FASG::InitConsole(game.W, game.H);
	FASG::SetFontSizeRatio(FASG::ConsoleFontRatios::_7x12);

	FASG::Sprite::SetCollisionCallback(Colisions);
	
	InitLogScreen();	

	while (game.login)
	{
		LogScreen();
		FASG::RenderFrame();

		while (game.executable)
		{
			Menu();

			while (game.difficulty)
			{
				Difficulty();
				FASG::RenderFrame();
				InitGame();

				while (game.gameplay)
				{
					MovementPlayer();
					DrawGame();
					FASG::RenderFrame();
				}
			}
				
			while (game.end)
			{
				GameOver();
				FASG::RenderFrame();
			}

			while (game.howToPlay)
			{
				HowToPlay();
				FASG::RenderFrame();
			}

			while (game.win)
			{
				finalBossSong.Stop();
				Win();
				FASG::RenderFrame();
			}
		}
	}

	FASG::DestroyConsole();
}

void InitGame()
{
	InitPlayer();
	InitStars();
	InitEnemies();	
}

void DrawGame()
{
	DrawStars();
	DrawPlayer();
	DrawEnemies();
}