// WarsOnTheStarsProyect.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
#include "Engine.h"
#include "Background.h"
#include "FAriasSimpleGraphics.h"

Game game;

//Height = 50
//Width = 200

int main()
{
	srand(time(NULL));
	game.W = 200;
	game.H = 50;

	FASG::InitConsole(game.W, game.H);

	Init_Stars();

	Draw_Stars();

	

	//InitPlayer();

	FASG::DestroyConsole();
}
