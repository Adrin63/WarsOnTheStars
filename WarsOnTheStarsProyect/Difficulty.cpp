#include "Difficulty.h"
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

//Posición del selector de dificultad
int contadorDifficulty = 1;

bool twoPlayers = false;
//Variables de game para determinar el punto donde estas del juego
extern Game game;

void Difficulty()
{
	//Mostrar graficamente dificultades
	FASG::WriteSpriteBuffer(90, 5, FASG::Sprite("Dificultad.txt"));
	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "PRACTICA", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "NORMAL", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "1 VIDA", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(35, FASG::EAligned::CENTER, "MODO 2 JUGADORES", FASG::EForeColor::LightWhite);
	
	//En funcion si hay 2 jugadores o no esta en rojo o verde
	switch (twoPlayers)
	{
	case true:
		FASG::WritePixelBuffer(161, 35, FASG::EBackColor::LightGreen);
			break;
	case false:
		FASG::WritePixelBuffer(161, 35, FASG::EBackColor::LightRed);
		break;
	}
	
	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "R PARA SELECCIONAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);

	//Subrayar la opción en la que estas
	switch (contadorDifficulty)
	{
	case 0:
		BackgroundWords(144, 155, 20);
		break;
	case 1:
		BackgroundWords(145, 154, 25);
		break;
	case 2:
		BackgroundWords(145, 154, 30);
		break;
	case 3:
		BackgroundWords(140, 159, 35);
		break;
	case 4:
		BackgroundWords(140, 159, 35);
		contadorDifficulty = 3;
		break;
	case -1:
		BackgroundWords(144, 155, 20);
		contadorDifficulty = 0;
		break;
	}

	FASG::RenderFrame();

	//_getch() y no IsKeyPressed para ir mas lentro entre opciones
	char DifChar = toupper(_getch());

	//Moverte entre opciones
	switch (DifChar)
	{
	case 'W':
		contadorDifficulty--;
		break;
	case 'S':
		contadorDifficulty++;
		break;
	}


	//Entrar al juego
	if (DifChar == 'R' && contadorDifficulty == 0)
	{
		game.gameplay = true;
	}

	if (DifChar == 'R' && contadorDifficulty == 1)
	{
		game.gameplay = true;
	}

	if (DifChar == 'R' && contadorDifficulty == 2)
	{
		game.gameplay = true;
	}

	if (DifChar == 'R' && contadorDifficulty == 3)
	{
		switch (twoPlayers)
		{
		case false:
			twoPlayers =true;
			break;
		case true:
			twoPlayers = false;
			break;
		}
	}
	if (DifChar == 'X')
	{
		contadorDifficulty = 1;
		game.difficulty = false;
	}
}

//enviar a Player que dificultad a sido elegida
Diff envDifficulty()
{
	switch (contadorDifficulty)
	{
	case 0:
		return Diff::INMORTAL;
	case 1:
		return Diff::NORMAL;
		break;
	case 2:
		return Diff::ONE;
		break;
	}
}

QuantityPlayers envQuantityPlayers()
{
	if (twoPlayers)
	{
		return TWOPLAYERS;
	}
	else
	{
		return ONEPLAYER;
	}
}