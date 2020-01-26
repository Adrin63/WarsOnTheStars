#include "Menu.h"7
#include "FAriasSimpleGraphics.h"
#include <conio.h>
#include "Engine.h"

//Posici�n del menu
int contadorMenu = 0;

//Variables de game para determinar el punto donde estas del juego
extern Game game;

void Menu()
{
	//Mostrar Graficamente el menu
	FASG::WriteSpriteBuffer(113, 5, FASG::Sprite("Menu.txt"));
	FASG::WriteStringBuffer(20, FASG::EAligned::CENTER, "JUGAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(25, FASG::EAligned::CENTER, "COMO JUGAR", FASG::EForeColor::LightWhite);
	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "E PARA SELECCIONAR", FASG::EForeColor::LightWhite);

	//Subrayar la opci�n en la que estas
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

	FASG::RenderFrame();

	//Moverte entre opciones
	if (FASG::IsKeyPressed('W'))
	{
		contadorMenu--;
	}

	if (FASG::IsKeyPressed('S'))
	{
		contadorMenu++;
	}

	//Entrar a la dificultad del juego y a posterior al juego
	if (FASG::IsKeyPressed('E') && contadorMenu == 0)
	{
		game.difficulty = true;
		game.end = false;
		game.gameplay = false;
		contadorMenu = 0;
	}

	//Entrar a los controles
	if (FASG::IsKeyPressed('E') && contadorMenu == 1)
	{
		game.howToPlay = true;
		contadorMenu = 0;
	}
}