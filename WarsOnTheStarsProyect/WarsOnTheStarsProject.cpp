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
	LogScreen();

	while (!game.executable)
	{
		//Menu();	para hacer el menu un contador 
		//FASG::RenderFrame();

		while (!game.gameplay)
		{
			MovementPlayer();
			//DrawObjects();
			Draw_Stars();
			DrawPlayer();
			DrawEnemies();
			FASG::RenderFrame();

		}

		FASG::RenderFrame();

	}

	FASG::DestroyConsole();
}
