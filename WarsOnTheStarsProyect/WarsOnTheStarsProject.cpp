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
#include "GameOver.h"

HANDLE hndl;

//FPS		FASG::WriteStringBuffer(0, 0, "FPS:" + std::to_string(1 / FASG::GetDeltaTime()),FASG::EForeColor::LightRed);

//extern Player player;
extern Game game;

int main()
{
	FASG::WAVESound miSonidoDePrueba;
	FASG::WAVESound Intro;
	FASG::WAVESound Muerte;
	Muerte.LoadSound("Muerte.wav");
	Intro.LoadSound("trascendedSong.wav");
	miSonidoDePrueba.LoadSound("manantial.wav");
	
	srand(time(NULL));
	game.W = 300; game.H = 60;

	FASG::InitConsole(game.W, game.H);
	FASG::SetFontSizeRatio(FASG::ConsoleFontRatios::_7x12);

	FASG::Sprite::SetCollisionCallback(Colisions);

	InitLogScreen();	
	

	while (game.login)
	{
		Muerte.Stop();
		miSonidoDePrueba.Stop();
		Intro.Play();
		LogScreen();
		FASG::RenderFrame();

		while (game.executable)
		{
			Menu();
			FASG::RenderFrame();

			while (game.difficulty)
			{
				Difficulty();
				InitGame();
				FASG::RenderFrame();

				while (game.gameplay)
				{
					Muerte.Stop();
					Intro.Stop();
					miSonidoDePrueba.Play();
					MovementPlayer();
					DrawGame();
					FASG::RenderFrame();

					while (game.gameOver)
					{
						Intro.Stop();
						miSonidoDePrueba.Stop();
						Muerte.Play();
						GameOver();
					}
				}
			}

			while (game.howToPlay)
			{
				HowToPlay();
				FASG::RenderFrame();
			}
		}
	}

	FASG::DestroyConsole();
}

void InitGame()
{
	InitPlayer();
	Init_Stars();
	InitEnemies();	
}

void DrawGame()
{
	Draw_Stars();
	DrawPlayer();
	DrawEnemies();
}