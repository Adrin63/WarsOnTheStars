#include "Menu.h"7
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

int contadorMenu = 0;

extern Game game;

void Menu()
{
		if (FASG::IsKeyPressed('W'))
		{
			contadorMenu--;
		}

		if (FASG::IsKeyPressed('S'))
		{
			contadorMenu++;
		}

		if (FASG::IsKeyPressed('E') && contadorMenu == 0)
		{
			game.difficulty = true;
			game.gameplay = false;
			contadorMenu = 0;
		}

		if (FASG::IsKeyPressed('E') && contadorMenu == 1)
		{
			game.howToPlay = true;
			contadorMenu = 0;
		}

		if (FASG::IsKeyPressed('C'))
		{
			game.executable = false;
			game.login = false;
		}

	FASG::WriteSpriteBuffer(113, 5, FASG::Sprite("Menu.txt"));

	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "JUGAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "COMO JUGAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "E PARA SELECCIONAR", FASG::EForeColor::LightWhite);

	FASG::WriteStringBuffer(55, FASG::EAligned::CENTER, "C PARA SALIR", FASG::EForeColor::LightWhite);

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