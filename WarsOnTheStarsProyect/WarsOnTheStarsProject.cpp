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
#include "Win.h"
#include "SecondPlayer.h"
HANDLE hndl;

//Variables de game para determinar el punto donde estas del juego y la canción final para pararla
extern Game game;
extern FASG::WAVESound finalBossSong;

int main()
{	
	//Inicialización del proyecto
	srand(time(NULL));
	game.W = 300; game.H = 60;
	FASG::InitConsole(game.W, game.H);
	FASG::SetFontSizeRatio(FASG::ConsoleFontRatios::_7x12);

	//Activar sistema de colisiones
	FASG::Sprite::SetCollisionCallback(Colisions);
	
	//Inicializar la Pantalla de Inicio
	InitLogScreen();	

	while (game.login)
	{
		//Imprimir Pantalla de Inicio
		LogScreen();

		while (game.executable)
		{
			//Imprimir Menu
			Menu();

			while (game.difficulty)
			{
				//Imprimir selector de dificultad e iniciar el juego
				InitGame();
				Difficulty();
				FASG::RenderFrame();
				

				while (game.gameplay)
				{
					//Bucle principal del juego
					MovementPlayer();
					MovementSecPlayer();
					DrawGame();
					FASG::RenderFrame();
				}
			}
				
			while (game.end)
			{
				//Parar canción del boss final y pantalla de muerte
				finalBossSong.Stop();
				GameOver();
			}

			while (game.howToPlay)
			{
				//Controles
				HowToPlay();	
			}

			while (game.win)
			{
				//Parar canción del boss final y pantalla de victoria
				finalBossSong.Stop();
				Win();
			}
		}
	}

	FASG::DestroyConsole();
}

void InitGame()
{
	InitPlayer();
	InitSecPlayer();
	InitStars();
	InitEnemies();	
}

void DrawGame()
{
	DrawStars(true);
	DrawPlayer();
	DrawSecPlayer();
	DrawEnemies();
}