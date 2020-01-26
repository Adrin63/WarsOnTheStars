#include "FAriasSimpleGraphics.h"
#include "Victoria.h"
#include "Engine.h"

//Variables de game para determinar el punto donde estas del juego
extern Game game;

void Win()
{
	//Mostar Graficamente Victoria
	FASG::WriteSpriteBuffer(100, 5, FASG::Sprite("Victoria.txt"));
	FASG::WriteStringBuffer(52, FASG::EAligned::CENTER, "PULSA X PARA VOLVER AL MENU", FASG::EForeColor::LightWhite);
	
	FASG::RenderFrame();

	//Volver al menu
	if (FASG::IsKeyPressed('X'))
	{
		game.win = false;
		game.executable = true;
	}

}
