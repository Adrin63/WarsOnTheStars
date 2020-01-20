#include "Difficulty.h"
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

int contadorDifficulty = 0;

extern Game game;

void Difficulty()
{
	bool Dif = false;

	if (!Dif)
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

		if (DifChar == 'E' && contadorDifficulty == 0)
		{
			game.executable = false;
			game.gameplay = false;
			game.difficulty = true;
		}

		if (DifChar == 'E' && contadorDifficulty == 1)
		{
			game.executable = false;
			game.gameplay = false;
			game.difficulty = true;
		}

		if (DifChar == 'E' && contadorDifficulty == 2)
		{
			game.executable = false;
			game.gameplay = false;
			game.difficulty = true;
		}
	}

	FASG::WriteSpriteBuffer(90, 5, FASG::Sprite("Dificultad.txt"));
	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "FACIL", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "NORMAL", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "DIFICIL", FASG::EForeColor::LightWhite);

	switch (contadorDifficulty)
	{
	case 0:
		BackgroundWords(146, 154, 20);
		break;
	case 1:
		BackgroundWords(146, 154, 25);
		break;
	case 2:
		BackgroundWords(146, 155, 30);
		break;
	case 3:
		BackgroundWords(146, 155, 30);
		break;
	case -1:
		BackgroundWords(146, 154, 20);
		contadorDifficulty = 0;
		break;
	}
}