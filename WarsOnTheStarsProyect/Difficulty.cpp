#include "Difficulty.h"
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

int contadorDifficulty = 1;

extern Game game;

Diff difficulty;

void Difficulty()
{
	char DifChar = toupper(_getch());

	switch (DifChar)
	{
	case 'W':
		contadorDifficulty--;
		break;
	case 'S':
		contadorDifficulty++;
		break;
	}

	if (DifChar == 'R' && contadorDifficulty == 0)
	{
		
		game.gameplay = true;
	}

	if (DifChar == 'R' && contadorDifficulty == 1)
	{
		difficulty = NORMAL;
		game.gameplay = true;
	}
	
	if (DifChar == 'R' && contadorDifficulty == 2)
	{
		difficulty = ONE;
		game.gameplay = true;
	}

	if (DifChar == 'X')
	{
		contadorDifficulty = 1;
		game.difficulty = false;
	}

	FASG::WriteSpriteBuffer(90, 5, FASG::Sprite("Dificultad.txt"));
	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "PRACTICA", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "NORMAL", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "1 VIDA", FASG::EForeColor::LightWhite);

	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "R PARA SELECCIONAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);

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
		BackgroundWords(145, 154, 30);
		contadorDifficulty = 2;
		break;
	case -1:
		BackgroundWords(144, 155, 20);
		contadorDifficulty = 0;
		break;
	}
}

Diff envDifficulty()
{
	switch (contadorDifficulty)
	{
	case 0:
		return INMORTAL;
	case 1:
		return NORMAL;
		break;
	case 2:
		return ONE;
		break;
	}
}