#include "Menu.h"
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

int contadorMenu = 0;

extern Game game;

void Menu()
{
	bool Menu = false;

	if (!Menu)
	{

		char DifChar = toupper(_getch());

		switch (DifChar)
		{
		case 'W':
			contadorMenu--;
			break;
		case 'S':
			contadorMenu++;
			break;
		}

		if (DifChar == 'E' && contadorMenu == 0)
		{
			game.executable = true;
			game.gameplay = false;
		}

		if (DifChar == 'E' && contadorMenu == 1)
		{
			game.executable = true;
			game.gameplay = true;
			game.difficulty = false;
		}
	}

	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "JUGAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "DIFICULTAD", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(30, FASG::EAligned::CENTER, "GLOSARIO", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(35, FASG::EAligned::CENTER, "COMO JUGAR", FASG::EForeColor::LightWhite);

	switch (contadorMenu)
	{
	case 0:
		BackgroundWords(146, 154, 20);
		break;
	case 1:
		BackgroundWords(143, 154, 25);
		break;
	case 2:
		BackgroundWords(144, 155, 30);
		break;
	case 3:
		BackgroundWords(143, 156, 35);
		break;
	case -1:
		BackgroundWords(146, 154, 20);
		contadorMenu = 0;
		break;
	case 4:
		contadorMenu = 3;
		BackgroundWords(143, 156, 35);
		break;
	}
}