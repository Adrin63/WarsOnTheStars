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

HANDLE hndl;

//FPS		FASG::WriteStringBuffer(0, 0, "FPS:" + std::to_string(1 / FASG::GetDeltaTime()),FASG::EForeColor::LightRed);


extern Player player;
extern Game game;

int main()
{
	srand(time(NULL));
	game.W = 300; game.H = 60;

	FASG::InitConsole(game.W, game.H);
	FASG::SetFontSizeRatio(FASG::ConsoleFontRatios::_7x12);

	InitPlayer();
	Init_Stars();
	InitEnemies();
	InitLogScreen();

	while (!game.login)
	{
		LogScreen();

		FASG::RenderFrame();
		while (!game.executable)
		{
			Menu();

			while (!game.gameplay)
			{
				MovementPlayer();
				//DrawObjects();
				Draw_Stars();
				DrawPlayer();
				DrawEnemies();
				FASG::RenderFrame();

			}

			while (!game.difficulty)
			{
				Difficulty();
				FASG::RenderFrame();
			}

			while (!game.glossary)
			{
				FASG::RenderFrame();
			}

			while (!game.howToPlay)
			{
				FASG::RenderFrame();
			}

			FASG::RenderFrame();
		}
	}

	FASG::DestroyConsole();
}
