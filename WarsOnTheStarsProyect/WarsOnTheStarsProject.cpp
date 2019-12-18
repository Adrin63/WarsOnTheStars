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

/*IsKeyPressed no puedes hacer switch case porque no puedes guardar el valor en una variable, pixeles cuadrados khbit va demasiado lento*/

extern Player player;
extern Game game;

int main()
{
	srand(time(NULL));
	game.W = 200; game.H = 50;

	FASG::InitConsole(game.W, game.H);

	InitPlayer();
	Init_Stars();
	LogScreen();

	while (!game.executable)
	{
		//Menu();	para hacer el menu un contador 
		//FASG::RenderFrame();

		while (!game.gameplay)
		{
			MovementPlayer();
			Draw_Stars();
			DrawPlayer();
			FASG::RenderFrame();

		}

		FASG::RenderFrame();

	}

	FASG::DestroyConsole();
}
