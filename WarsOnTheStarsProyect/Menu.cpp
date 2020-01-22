#include "Menu.h"
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

int contadorMenu = 0;

extern Game game;

void Menu()
{
	bool Menu = true;

	if (Menu)
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
			game.executable = false;
			game.gameplay = false;
			game.difficulty = true;
		}

		if (DifChar == 'E' && contadorMenu == 1)
		{
			game.executable = false;
			game.howToPlay = true;
		}
	}
	FASG::WriteSpriteBuffer(113, 5, FASG::Sprite("Menu.txt"));

	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "JUGAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "COMO JUGAR", FASG::EForeColor::LightWhite);

	switch (contadorMenu)
	{
	case 0:
		BackgroundWords(146, 154, 20);
		break;
	case 1:
		BackgroundWords(143, 156, 25);
		break;
	case 2:
		BackgroundWords(143, 156, 25);
		contadorMenu = 1;
		break;
	case -1:
		BackgroundWords(146, 154, 20);
		contadorMenu = 0;
		break;
	}
}